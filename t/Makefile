all: test bday

test: test-a test-so
	( echo test-a ; ./test-a ) | less
	( echo test-so ; export LD_LIBRARY_PATH=..:$(LD_LIBRARY_PATH) ; ./test-so ) | less

bday: bday-a 
	./bday-a > marty-bdays.ics
	( echo bday-a ; cat marty-bdays.ics ) | less

clean:
	rm -f test-a test-so bday-a

test-a: test.c ../libmtime.a
	gcc -I.. -L.. -static -o test-a test.c ../libmtime.a

test-so: test.c ../libmtime.so.1.0
	gcc -I.. -L.. -lmtime -o test-so test.c

bday-a: bday.c ../libmtime.a
	gcc -I.. -L.. -static -o bday-a bday.c ../libmtime.a

