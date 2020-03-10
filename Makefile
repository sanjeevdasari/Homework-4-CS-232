PROG   = main
CC     = g++
CFLAGS = -o
LFLAGS = $(PROG).cpp CSShell.cpp Path.cpp

$(PROG): $(PROG).cpp
	$(CC) $(CFLAGS) $(PROG) $(LFLAGS)

clean:
	rm -f $(PROG) a.out *~ *# *.o *.out
