all: calculator.o test

calculator.o: calculator.c calculator.h
    gcc -c calculator.c -o calculator.o

test: calculator.o test.c
    gcc calculator.o test.c -o test

clean:
    rm -f *.o test

