CFLAGS =-Wall \
		-g
		

all: alias

alias: alias.c
	$(CC) $(CFLAGS) -o $@ $^
	
clean:
	rm -rf alias
