objects := mtime.o mlocaltime.o masctime.o mofftime.o

all: libmtime.a libmtime.so

test: all
	make -C t

clean:
	rm -f libmtime.a libmtime.so* *.o
	make -C t clean

libmtime.a: mtime.o ${objects}
	ar rs libmtime.a ${objects}

libmtime.so: ${objects}
	ld -shared -soname libmtime.so.1 -o libmtime.so.1.0 ${objects}
	ln -fs libmtime.so.1.0 libmtime.so.1
	ln -fs libmtime.so.1.0 libmtime.so

mtime.o: mtime.c mtime.h
	gcc -fPIC -c -o mtime.o mtime.c

mofftime.o: mofftime.c mtime.h mtimedefs.h
	gcc -fPIC -c -o mofftime.o mofftime.c

masctime.o: masctime.c mtime.h mtimedefs.h
	gcc -fPIC -c -o masctime.o masctime.c

mlocaltime.o: mlocaltime.c mtime.h mtimedefs.h
	gcc -fPIC -c -o mlocaltime.o mlocaltime.c

install: all
	cp -prad libmtime.* /usr/local/lib
	cp -prad mtime.h /usr/local/include
	ldconfig

