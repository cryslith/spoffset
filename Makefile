.PHONY: all clean

all: spoffset

spoffset:
	gcc -o spoffset spoffset.c

clean:
	-rm spoffset 2>/dev/null
