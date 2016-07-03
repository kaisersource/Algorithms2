
bin/lista.o : src/lista.c src/lista.h
	gcc -c src/lista.c -o bin/lista.o

exe/BookList: bin/lista.o src/mainlista.c 
	gcc  bin/lista.o src/mainlista.c -o exe/BookList
run:exe/BookList
	./exe/BookList
