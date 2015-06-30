/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>
#include "stack.h"

/* Local function prototype */
static bool is_oper(char s);
static int do_oper(int op1, int op2, int operator);


int main ()
{
  stack_t s;
  char *exp = "623+-382/+*2$3+";
  int idx = 0;
  int flag = 0;

  init(&s);
  
  for(idx = 0; idx < strlen(exp); idx++) {
    if(isdigit(exp[idx])) {
      push(&s, exp[idx] - '0');
    }else if(is_oper(exp[idx])) {
      if(num_items(&s) > 1) {
	int op2 = pop(&s);
	int op1 = pop(&s);
	int res = do_oper(op1, op2, exp[idx]);
	push(&s, res);
      }else {
	flag = 1;
      }
    }else {
      flag = 1;
    }
  }
  if(flag == 0 && !is_empty(&s)) {
    printf("Answer of post fix expression \"%s\" is %d\n", exp, pop(&s));
  }else {
    printf("ERROR postfix expression \"%s\" incorrect \n", exp); 
  }
  return 0;
}

static bool is_oper(char s)
{
  if(s == '+' || s == '-' || s == '*' || s == '/' || s == '$') {
    return true;
  } else {
    return false;
  }
}

static int do_oper(int op1, int op2, int operator)
{
  if(operator == '+') {
    return op1 + op2;
  }else if (operator == '-') {
    return op1 - op2;
  }else if (operator == '*') {
    return op1 * op2;
  }else if (operator == '/') {
    return op1 / op2;
  }else if (operator == '$') {
    return pow(op1, op2);
  }else {
    return 0;
  }
}
