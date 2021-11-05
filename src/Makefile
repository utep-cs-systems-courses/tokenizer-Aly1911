


tokenizer.o: tokenizer.h tokenizer.c
history.o: history.h history.c
#uimain.o: tokenizer.h #history.h 


tokenizer: history.o tokenizer.o
	gcc -o tokenizer history.o tokenizer.o

clean:

	rm -f *.o tokenizer


run:

	./tokenizer
