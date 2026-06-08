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



culm-test: obj/test/test.o obj/test/rttest.o
	gcc obj/test/test.o obj/test/rttest.o -o culm-test

	
obj/test/test.o: test/test.c
	@mkdir -p obj/test/
	$(CC) -c $< -o $@

obj/test/rttest.o: test/rttest.c
	@mkdir -p obj/test/
	$(CC) -c $< -o $@


clean:
	rm -rf obj/