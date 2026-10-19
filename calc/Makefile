CC = gcc
AR = ar
CFLAGS = -Wall -Wextra -g -O0 -fPIC
CPPFLAGS = -I./lib

OBJECTS = lib/add.o lib/subtract.o lib/multiply.o lib/divide.o
TARGETS = calc_static calc_shared calc_dynamic

.PHONY: all clean

all: $(TARGETS)

calc_static: main.o lib/libcalc.a
	$(CC) $(CFLAGS) -o $@ main.o lib/libcalc.a

calc_shared: main.o lib/libcalc.so
	$(CC) $(CFLAGS) -o $@ main.o -L./lib -lcalc -Wl,--rpath="$(CURDIR)/lib"

calc_dynamic: main_dynamic.o
	$(CC) $(CFLAGS) -rdynamic -o $@ $< -ldl

main.o: main.c lib/calc.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

main_dynamic.o: main_dynamic.c
	$(CC) $(CFLAGS) -c $< -o $@

lib/%.o: lib/%.c lib/calc.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

lib/libcalc.a: $(OBJECTS)
	$(AR) rcs $@ $^

lib/libcalc.so.1.0.0: $(OBJECTS)
	$(CC) $(CFLAGS) -shared -Wl,-soname,libcalc.so.1 -o $@ $^

lib/libcalc.so.1: lib/libcalc.so.1.0.0
	ln -sfn libcalc.so.1.0.0 $@

lib/libcalc.so: lib/libcalc.so.1
	ln -sfn libcalc.so.1.0.0 $@

clean:
	rm -f $(TARGETS) main.o main_dynamic.o $(OBJECTS)
	rm -f lib/libcalc.a lib/libcalc.so lib/libcalc.so.1 lib/libcalc.so.1.0.0
