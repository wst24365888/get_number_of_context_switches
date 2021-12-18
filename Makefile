setup:
	./setup.sh

test:
	gcc -no-pie -o test.o test.c && ./test.o