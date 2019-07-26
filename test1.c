test:test.c
	gcc -o $@ $^
.PFONY:clean
	rm -f test
