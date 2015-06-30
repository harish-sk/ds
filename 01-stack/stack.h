#ifndef __STACK__
#define __STACK__

#include <stdbool.h>

#define STACKSIZE 128
//#define STACK_DEBUG_PRINT 1

typedef struct stack_tag {
  int items[STACKSIZE];
  int top;
}stack_t;

void init(stack_t *p_stack);
int pop(stack_t *p_stack);
int popandtest(stack_t *p_stack, bool *underflow);
void push(stack_t *ps, int item);
void pushandtest(stack_t *ps, int item, bool *overflow);
bool is_empty(stack_t *ps);
bool is_full(stack_t *ps);
void display(stack_t *ps);
int peep(stack_t *ps);
int peepandtest(stack_t *ps, bool *underflow);

#endif
