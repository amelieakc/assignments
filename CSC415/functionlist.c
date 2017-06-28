/*
Author: Amelie Cameron
Professor: Hao Yue
CSC 415 Summer'17
Assignment 2: List of Functions
gcc functionlist.c
Due 06/21/17 
*/

#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//option 1
void hello(){
  pid_t pid;
  //create new process
  pid = fork();
  if(pid < 0){
    //error occurred
    printf("Fork failed.");
  }else if(pid == 0){
    //print hello world!
    printf("Hello World!\n");
    exit(0);
  }else{
    //parent process waits for child process to complete
    wait(NULL);
  }
}

//option 2
void list(){
  pid_t pid;
  //create new process
  pid = fork();
  if(pid < 0){
    //error occurred
    printf("Fork failed.");
  }else if(pid == 0){
    //use excelp() to list all files in the current directory
    execlp("/bin/ls","ls", NULL); 
  }else{
    //parent process waits for child process to complete
    wait(NULL);
  }
}

void menu(){
  int select;
  //create 1024-byte buffer
  char buffer[1024];
  do{
    //print menu options
    printf("\nMenu\n"); 
    printf("1. Hello World!\n"); 
    printf("2. List Files\n"); 
    printf("3. Exit\n");
    printf("Please select:\n"); 
    //use fgets() to save input from user
    fgets(buffer, 1024, stdin);
    //convert char to int
    select = atoi(buffer);
    //option 1
    if(select == 1){
      hello();
    }else if(select == 2){
      //option 2
      list();
    }else if(select == 3){
      //option 3
      break;
    }
    else{
      //incorrect input
      printf("Invalid choice!\n");
    } 
    //continue unless exit is selected
  } while(select != 3);
  wait(NULL);
}

int main(){
  //call menu
  //when user selects an option, menu() will call either hello() or list() or exit
  menu();
}


  
