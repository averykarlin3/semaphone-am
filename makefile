make: control.o writing.o
	gcc control.o -o control
	gcc writing.o -o writing

control.o: control.c sema.h
	gcc -c control.c

writing.o: writing.c sema.h
	gcc -c writing.c

create: control
	./control -c

remove: control
	./control -r

write: writing
	./writing

clean:
	rm *.o
