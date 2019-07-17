CFLAGS =-Wall \
		-g
		

all: makealias

makealias: alias.c
	$(CC) $(CFLAGS) -o $@ $^
	
clean:
	rm -rf makealias
