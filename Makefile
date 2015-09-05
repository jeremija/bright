PREFIX=/usr/local

.PHONY: all
all:
	gcc brightness.c -o brightness

.PHONY: clean
clean:
	rm -f brightness

.PHONY: install
install:
	cp brightness $(PREFIX)/bin/brightness
	chmod 4755 $(PREFIX)/bin/brightness

.PHONY: uninstall
uninstall:
	rm $(PREFIX)/bin/brightness
