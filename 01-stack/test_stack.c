#include <stdio.h>
#include "stack.h"

int main()
{
  stack_t s;
  init(&s);
  push(&s, 10);
  push(&s, 20);
  push(&s, 90);
  display(&s);
  pop(&s);
  display(&s);
  peep(&s);
  display(&s);
  return 0;
}
