CC	= gcc
CFLAGS	= -O0 -g -Wall
LDFLAGS = -fno-stack-protector
objects	= v1 v2 v3
v1	= gcd1.o test.o
v2	= gcd2.o test.o
v3	= gcd3.o test.o
srcs = gcd1.c gcd2.c gcd3.c

CFLAGIA32_AS = -O0 -S -m32 -g -Wall
CFLAGX64_AS = -O0 -S -g -Wall

default: all

.PHONY: default clean arm IA32 X64
IA32: $(srcs)
	$(CC) $(CFLAGIA32_AS) $^
X64: $(srcs)
	$(CC) $(CFLAGX64_AS) $^

#run the tests
all: $(objects)
	for obj in $(objects) ; do\
			./$$obj.o;\
			done
v1: $(v1)
	$(CC) $(LDFLAGS) -o $@.o $^
v2: $(v2)
	$(CC) $(LDFLAGS) -o $@.o $^
v3: $(v3)
	$(CC) $(LDFLAGS) -o $@.o $^
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
	rm -f $(objects) *.o



