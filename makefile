main: main.cpp queue.cpp queue.h test.cpp test.h
	g++ main.cpp queue.cpp test.cpp
clean:
	rm a.out
start:
	./a.out

