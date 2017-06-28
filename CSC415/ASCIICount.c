#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define THREADS 8

void *runner(void *param); /* threads call this function */
const int size = 65536;
char buffer[size] = {0};
int globalCounter[size] = {0};

typedef struct ThreadArgs {
  int tid;
  int left;
  int right;
} ThreadArgs;

/*
  Combine all of the counter spaces
 */
int* reduce() {
  int* countArray = malloc(128 * sizeof(int));
  
  // clear count array
  for(int i = 0; i < 128; ++i)
    countArray[i] = 0;
  
  for(int i = 33; i <= 126; ++i){
    for(int tid = 1; tid <= 8; ++tid){  
      countArray[i] += globalCounter[i*tid];
    }
  }
  return countArray;
}


int main(int argc, char *argv[])
{
  pthread_attr_t attr; /* set of thread attributes */
  pthread_t* threads = malloc(THREADS * sizeof(pthread_t));

  FILE *test;
  
  test = fopen("test.txt", "r");
  if(test == NULL){
    fputs("File error", stderr);
    exit(1);
  } else if(test){
    while(fgets(buffer, size, test))
      {
	//fputs(buffer, stdout);
      }
    fclose(test);
  }

  /* get the default attributes */
  pthread_attr_init(&attr);

  int buffer_len = strlen(buffer);
  int chunk_size =  buffer_len / THREADS;

  /* create the threads */
  for(int i = 0; i < THREADS; ++i){
    struct ThreadArgs* args = (struct ThreadArgs*)malloc(sizeof(struct ThreadArgs));
    args->tid = i+1;
    args->left = i*chunk_size;
    args->right = i*chunk_size + chunk_size;

    pthread_create(&threads[i], &attr, runner, args);
    //    printf("created thread ");
    //printf("%d\n",i+1);
  }
  /* wait for the thread to exit */
  for(int i = 0; i < THREADS; ++i)
    pthread_join(threads[i], NULL);

  // check the global counter
  // DEBUGGING
  for(int i = 0; i < size; ++i) {
    if (globalCounter[i] != 0)
      printf("%d:%d\n", i, globalCounter[i]);
  }

  int *countArray = reduce();
  for (int i = 0; i < size; ++i){
    if(countArray[i] != 0){
      char c = i;
      printf("%d : ", i);
      printf("%c : ", c);
      printf("%d \n", countArray[i]);
    }
  }
}


/* The thread will begin control in this function */

void *runner(void *args)
{
  ThreadArgs* mapper_args = args;
  //printf("I'm thread %d\n", mapper_args->tid);

  //printf("%d %d\n", mapper_args->left, mapper_args->right);

  for (int i = mapper_args->left; i < mapper_args->right; ++i)
    {
      int temp = 0;
      temp = buffer[i];
      printf("%c ", buffer[i]);
      if((temp >= 33) && (temp <= 126)) {
	//printf("%c\n", (char)temp);
	//printf("%d\n", temp);
	int counter_index = temp * mapper_args->tid;
	globalCounter[counter_index]++;
      }
    }
  
  pthread_exit(0);
}
