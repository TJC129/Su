CC	= gcc
CFLAGS	= -O0 -g -Wall 
LDFLAGS = -fno-stack-protector
objects	= v1 v2 v3
v1	= gcd1.o test.o
v2	= gcd2.o test.o
v3	= gcd3.o test.o

default: all

.PHONY: default clean run arm

#run the tests
all: $(objects)
	for obj in $(objects) ; do\
			./$$obj;\
			done
v1: $(v1)
	$(CC) $(LDFLAGS) -o $@ $^ 
v2: $(v2)
	$(CC) $(LDFLAGS) -o $@ $^ 
v3: $(v3)
	$(CC) $(LDFLAGS) -o $@ $^ 
gcd1.o: gcd1.c
gcd2.o: gcd2.c
gcd3.o: gcd3.c
test.o: test.c
# $< first prerequisite
# $^ list of all prerequisites
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
%.o: %.s
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(objects) gcd



