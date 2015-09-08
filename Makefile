PREFIX=/usr/local

.PHONY: all
all:
	gcc bright.c -o bright

.PHONY: clean
clean:
	rm -f bright

.PHONY: install
install:
	cp bright $(PREFIX)/bin/bright
	chmod 4755 $(PREFIX)/bin/bright

.PHONY: uninstall
uninstall:
	rm $(PREFIX)/bin/bright
