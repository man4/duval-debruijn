CC = g++
CFLAGS = -O3
MAIN = duval

all: $(MAIN)

$(MAIN): $(MAIN).cpp
	$(CC) $(CFLAGS) -o $(MAIN) $(MAIN).cpp

clean:
	rm -f *.o $(MAIN) $(MAIN).exe
