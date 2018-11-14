
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

char ** parse_args( char * line ){
  char ** args = malloc(256);
  char * token;
  int i = 0;
  while(token){
    token = strsep(&line, " ");
    args[i] = token;
    i++;
  }
  return args;
}

// To test use this is the command line "ls -a -l"
int main(int argc, char *argv[]){
  char* str = malloc(50);
  str = argv[1];
  printf("Looking into string: %s\n", str );
  char ** arr= parse_args(str);
  int i = 0;
  while(arr[i]){
      printf("arr[%d]: %s\n", i, arr[i]);
      i++;
  }
  return 0;
}
