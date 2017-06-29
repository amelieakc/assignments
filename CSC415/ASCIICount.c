#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define THREADS 8

void *runner(void *args); /* threads call this function */
const int size = 65536;
char buffer[size] = {0};
int globalCounter[size] = {0};
int ASCII_SIZE = 128;

typedef struct ThreadArgs {
  int tid;
  int left;
  int right;
} ThreadArgs;

/* Combine all of the counter spaces */
int* reduce() {
  int* countArray = malloc(128 * sizeof(int));
  
  // clear count array
  for(int i = 0; i <= 128; ++i)
    countArray[i] = 0;
  
  for(int i = 33; i <= 126; ++i){
    for(int tid = 0; tid < 8; ++tid){
      int bulk_head = ASCII_SIZE * tid;
      countArray[i] += globalCounter[bulk_head + i];
    }
  } 
  return countArray;
}


/* The thread will begin control in this function */
void *runner(void *args)
{
  ThreadArgs* mapper_args = args;
  
  for (int i = mapper_args->left; i < mapper_args->right; ++i)
    {
      int temp = 0;
      temp = buffer[i];
      if((temp >= 33) && (temp <= 126)) {
	int bulk_head = ASCII_SIZE * mapper_args->tid;
	int counter_index = bulk_head + temp;
	globalCounter[counter_index]++;
      } 
    }
  pthread_exit(0);
}


int main(int argc, char *argv[])
{
  pthread_attr_t attr; /* set of thread attributes */
  pthread_t* threads = malloc(THREADS * sizeof(pthread_t));

  FILE *test;
  
  test = fopen(argv[1], "r");
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
  //printf("buffer length: %d, chunk size: %d", buffer_len, chunk_size);

  /* create the threads */
  for(int i = 0; i < THREADS; ++i){
    struct ThreadArgs* args = (struct ThreadArgs*)malloc(sizeof(struct ThreadArgs));
    args->tid = i;
    args->left = i*chunk_size;
    args->right = i*chunk_size + chunk_size;
    
    pthread_create(&threads[i], &attr, runner, args);
  }
 
  /* wait for the thread to exit */
  for(int i = 0; i < THREADS; ++i)
    pthread_join(threads[i], NULL);
  
  int *countArray = reduce();

  for (int i = 0; i < size; ++i){
    if(countArray[i] != 0){
      char c = i;
      printf("%c : ", c);
      printf("%d \n", countArray[i]);
    }
  }
}
