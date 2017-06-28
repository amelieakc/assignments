#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define THREADS 8

void *runner(void *param); /* threads call this function */
const int size = 65536;
char buffer[size] = {};


typedef struct ThreadArgs {
  int left;
  int right;
  
} ThreadArgs;


int* countBuffer(const int left, const int right){
  int* countArray = malloc(128 * sizeof(int));

  for (int i = left; i < right; ++i)
    {
      int temp = 0;
      temp = buffer[i];
      //printf("%d ", buffer[i]);
      if((temp >= 33) && (temp <= 126))
	countArray[temp]++;
    }

  return countArray;
}


int main(int argc, char *argv[])
{
  pthread_t tid; /* the thread identifier */
  pthread_attr_t attr; /* set of thread attributes */
  
  FILE *test;
  //char buffer[size] = {};
  //int countArray[size] = {};
  
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

  int* countArray = countBuffer(0, size);
  for (int i = 0; i < size; ++i){
    if(countArray[i] != 0){
      char c = i;
      printf("%c : ", c);
      printf("%d \n", countArray[i]);
    }
  }

  /* get the default attributes */
  pthread_attr_init(&attr);

  int buffer_len = strlen(buffer);
  int chunk_size =  buffer_len / THREADS;

  /* create the threads */
  for(int i = 0; i < THREADS; ++i){
    struct ThreadArgs* args = (struct ThreadArgs*)malloc(sizeof(struct ThreadArgs));
    args->left = i*chunk_size;
    args->right = i*chunk_size + chunk_size;

    pthread_create(&tid, &attr, runner, args);
    printf("created thread ");
    printf("%d\n",i+1);
  }
  /* wait for the thread to exit */
  pthread_join(tid,NULL);
}


/* The thread will begin control in this function */

void *runner(void *args)
{
  ThreadArgs* mapper_args = args;
  printf("%d %d\n", mapper_args->left, mapper_args->right);
  int* countArray = malloc(128 * sizeof(int));

  for (int i = mapper_args->left; i < mapper_args->right; ++i)
    {
      int temp = 0;
      temp = buffer[i];
      //printf("%d ", buffer[i]);
      if((temp >= 33) && (temp <= 126))
	countArray[temp]++;
    }
  
  pthread_exit(0);
}
