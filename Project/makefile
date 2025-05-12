CC=g++
CFLAGS=-I.
DEPS = mc.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

mc: main.o mc.o 
	$(CC) -o MC_integrator main.o mc.o 