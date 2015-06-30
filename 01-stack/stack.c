#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

#if defined(STACK_DEBUG_PRINT)
#define DEBUG(...) printf(__VA_ARGS__)
#else
#define DEBUG(...)
#endif

void init(stack_t *ps)
{
  ps->top = 0;
}
int pop(stack_t *ps)
{
  int ret;
  if(is_empty(ps)){
    printf("ERROR: trying to pop from empty stack\n");
    exit(0);
  }else {
    ret =ps->items[ps->top--];
    DEBUG("POP %d\n", ret);
    return ret;
  }
}
int popandtest(stack_t *ps, bool *underflow)
{
  int ret;
  if(is_empty(ps)){
    *underflow = true;
    DEBUG("POPANDTEST Failed; Underflow detected\n", ret);
  }else {
    *underflow = false;
    ret =ps->items[ps->top--];
    DEBUG("POPANDTEST %d\n", ret);
    return ret;
  }
}
void push(stack_t *ps, int item)
{
  if(is_full(ps)) {
    printf("ERROR: trying to push to full stack\n");
    exit(0);
  }else {
    DEBUG("PUSH %d\n", item);
    ps->items[++ps->top] = item;
  }
}
void pushandtest(stack_t *ps, int item, bool *overflow)
{
  if(is_full(ps)) {
    *overflow = true;
    DEBUG("PUSHANDTEST failed; overflow detected\n");
  }else {
    *overflow = false;
    DEBUG("PUSHANDTEST %d\n", item);
    ps->items[++ps->top] = item;
  }
}

bool is_empty(stack_t *ps)
{
  bool ret;
  if(ps->top == 0) {
    ret = true;
  }else {
    ret = false;
  }
  return ret;
}
bool is_full(stack_t *ps)
{
  bool ret;
  if(ps->top == (STACKSIZE - 1)) {
    ret = true;
  }else {
    ret = false;
  }
  return ret;
}
void display(stack_t *ps)
{
  int idx;
  printf("Stack is ");
  if(is_empty(ps)) {
    printf("EMPTY\n");
  }else {
    for(idx = 1; idx <= ps->top; idx++) {
      printf("\t%d", ps->items[idx]);
    }
    printf("\n");
  }
}
int peep(stack_t *ps)
{
  int ret;
  if(is_empty(ps)){
    printf("ERROR: trying to pop from empty stack\n");
    exit(0);
  }else {
    ret = ps->items[ps->top];
    DEBUG("PEEP %d\n", ret);
    return ret;
  }
}
int peepandtest(stack_t *ps, bool *underflow)
{
  int ret;
  if(is_empty(ps)){
    *underflow = true;
    DEBUG("PEEPANDTEST failed; underflow detected\n", ret);
  }else {
    *underflow = false;
    ret = ps->items[ps->top];
    DEBUG("PEEPANDTEST %d\n", ret);
    return ret;
  }
}
