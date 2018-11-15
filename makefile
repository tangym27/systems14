all: arg.c
	gcc arg.c
run:
	./a.out "ls -a -l"
clean: 
	rm *.out
