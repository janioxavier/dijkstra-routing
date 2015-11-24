C_COMP=g++
FONTES=$(wildcard *.cpp)
HEADERS=$(wildecard *.h)

.PHONY: all clean tar

all: routing

routing : $(FONTES:.c=.o)
	$(C_COMP) -o $@ $^

%.o: %.c $(HEADRES)
	$(C_COMP) -c $< -o $@

clean:
	rm -f *.o routing *~

tar:
	tar cvjf routing.tar.bz2 $(FONTES) $(HEADERS)
