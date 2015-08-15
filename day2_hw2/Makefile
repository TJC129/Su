CC	= gcc
CFLAGS	= -O0 -g -Wall 
LDFLAGS = -fno-stack-protector
objects	= v1 v2 v3
v1	= phonebook1.o test.o
v2	= phonebook2.o test.o
v3	= phonebook3.o test.o

default: all

.PHONY: default clean run

#run the tests
all: $(objects)
	for obj in $(objects) ; do\
			perf stat -e cache-misses ./$$obj;\
			done
v1: $(v1)
	$(CC) $(LDFLAGS) -o $@ $^ 
v2: $(v2)
	$(CC) $(LDFLAGS) -o $@ $^ 
v3: $(v3)
	$(CC) $(LDFLAGS) -o $@ $^ 
phonebook1.o: phonebook1.c
phonebook2.o: phonebook2.c
phonebook3.o: phonebook3.c
test.o: test.c
# $< first prerequisite
# $^ list of all prerequisites
%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $<
%.o: %.s
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	rm -f $(objects) phonebook1.o phonebook2.o phonebook3.o test.o



