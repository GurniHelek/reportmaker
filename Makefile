
NAME = reportmaker
IDIR =./
CC = gcc
CFLAGS = -I$(IDIR) -Wall
ODIR = .

_DEPS = *.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

#_OBJ = *.o
#OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


#$(ODIR)/%.o: %.c $(DEPS)
#	$(CC) -c -o $@ $< $(CFLAGS)

$(NAME): *.c
	gcc -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f *.o *~ core $(INCDIR)/*~
