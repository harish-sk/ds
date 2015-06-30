#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"

int main()
{
  char *str = "[(2+3)*(3+10)]";
  stack_t s;
  int idx;
  bool flag = false;

  init(&s);

  for(idx = 0; idx < strlen(str); idx++) {
    if(str[idx] == '(' || str[idx] == '[' || str[idx] == '{') {
      push(&s, str[idx]);
    }else if(str[idx] == ')' || str[idx] == ']' || str[idx] == '}') {
      if(!is_empty(&s)) {
	char temp = pop(&s);
	if(!((temp == '(' && str[idx] == ')')
	     || (temp == '[' && str[idx] == ']')
	     || (temp == '{' && str[idx] == '}'))){
	  flag = true;
	}
      }else {
	flag = true;
      }
    }
  }

  if(!is_empty(&s)) {
    flag = true;
  }
  if(flag == false) {
    printf("Expression is balanced\n");
  }else {
    printf("Expression is not balanced\n");
  }
}
