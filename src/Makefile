


OBJS= tokenizer.o uimain.o


all: tokenizer


tokenizer.o: tokenizer.h
history.o: history.h
uimain.o: tokenizer.h #history.h 


tokenizer: $(OBJS)

clean:

	rm -f *.o tokenizer


run:

	./tokenizer
