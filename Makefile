.PHONY: all
all:
	gcc brightness.c -o brightness

.PHONY: clean
clean:
	rm -f brightness

