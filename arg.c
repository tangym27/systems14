
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
    // Seperate based on spaces between args
    token = strsep(&line, " ");
    args[i] = token;
    i++;
  }
  return args;
}

// To test use this is the command line "ls -a -l"
int main(int argc, char *argv[]){
  char* str = malloc(50);
  if(argc <=  1){
	  printf("Enter a string to be parsed:\n");
	  fgets(str,50,stdin);
  }
  else{ str = argv[1];
  }
  
  printf("Looking into string: %s\n", str);

  char ** arr = parse_args(str);
  int i =0;
  while(arr[i]){
	printf("arr[%d]: %s\n", i, arr[i]);
	i++;
    }

  //arr[strlen(arr) - 1 ] = NULL;
  
  execvp(arr[0],arr);

  return 0;
  }
