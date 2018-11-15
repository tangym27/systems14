
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
  char* str_holder = malloc(50);

  if(argc <=  1){
	  printf("Enter a string to be parsed (example: \"ls -a -l\"):\n");
	  fgets(str_holder,50,stdin);
    // If user gives "ls -a -l", this will get rid of the ""
    for (int j = 1; j < strlen(str_holder)-2; j++){
      // printf("asize%lu\n", strlen(str_holder) );
      str[j-1] = str_holder[j];
      //printf("str is %c, str_holder is %c\n", str[j-1], str_holder[j] );
    }
  }
  else{
    str = argv[1];
  }

  printf("-------------------------------\nLooking into string: %s\n", str);

  char ** arr = parse_args(str);
  int i =0;
  while(arr[i]){
	printf("arr[%d]: %s\n", i, arr[i]);
	i++;
  }
  printf("-------------------------------\nTESTING USING EXECVP:\n");
  //arr[strlen(arr) - 1 ] = NULL;

  execvp(arr[0],arr);

  return 0;
  }
