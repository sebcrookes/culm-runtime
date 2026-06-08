CC = gcc

all: culm-runtime culm-test

culm-runtime: obj/src/main.o obj/src/memspace.o obj/src/runtime.o obj/src/syscall.o
	gcc obj/src/main.o obj/src/memspace.o obj/src/runtime.o obj/src/syscall.o -o culm-runtime

obj/src/main.o: src/main.c
	@mkdir -p obj/src/
	$(CC) -c $< -o $@

obj/src/memspace.o: src/memspace.c
	@mkdir -p obj/src/
	$(CC) -c $< -o $@

obj/src/runtime.o: src/runtime.c
	@mkdir -p obj/src/
	$(CC) -c $< -o $@

obj/src/syscall.o: src/syscall.c
	@mkdir -p obj/src/
	$(CC) -c $< -o $@



culm-test: obj/test/test.o
	gcc obj/test/test.o -o culm-test

	
obj/test/test.o: test/test.c
	@mkdir -p obj/test/
	$(CC) -c $< -o $@
