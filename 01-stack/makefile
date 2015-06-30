# Simple makefile

%.o : 

.PHONY: test_stack
test_stack: test_stack.c stack.c stack.h
	cc test_stack.c stack.c -o test_stack.out

.PHONY: balance_exp
balance_exp: balance_exp.c stack.c stack.h
	cc balance_exp.c stack.c -o balance_exp.out

.PHONY: clean
clean:
	rm -rf *.o test_stack balance_exp.out
	rm -f *~
