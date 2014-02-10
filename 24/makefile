
CFLAG=-std=c++0x

run: s
	./s
s: main.cpp
	c++ $(CFLAG) main.cpp -o s

test:
	c++ t.cpp -o a.out
	./a.out
	rm a.out
