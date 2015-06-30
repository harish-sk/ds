# Simple makefile

CFLAG := -g

%.o : 

.PHONY: test_stack
test_stack: test_stack.c stack.c stack.h
	cc $(CFLAG) test_stack.c stack.c -o test_stack.out

.PHONY: balance_exp
balance_exp: balance_exp.c stack.c stack.h
	cc $(CFLAG) balance_exp.c stack.c -o balance_exp.out

.PHONY: eval_post_fix
eval_post_fix: eval_post_fix.c stack.c stack.h
	cc $(CFLAG) eval_post_fix.c stack.c -o eval_post_fix.out -lm

.PHONY: clean
clean:
	rm -rf *.o *.out
	rm -f *~
