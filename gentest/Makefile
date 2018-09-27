BIN = libgentest.a

SRCS = $(wildcard *.c)
OBJS = $(patsubst %.c,%.o,$(SRCS))


all: $(BIN)

$(BIN): $(OBJS)
	ar rcs $(BIN) $(OBJS)

%.o : %.c
	gcc -I ./ -c $< -o $@


.PHONY : clean
clean:
	@rm -f $(BIN)
	@rm -f *.o
