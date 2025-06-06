all: restqueue

restqueue: main.o filaCozinha.o listaPedidos.o cardapio.o
	gcc -Wall -Wextra -std=c11 main.o filaCozinha.o listaPedidos.o cardapio.o -o restqueue

main.o: main.c
	gcc -c main.c

filaCozinha.o: filaCozinha.c
	gcc -c filaCozinha.c

listaPedidos.o: listaPedidos.c
	gcc -c listaPedidos.c

cardapio.o: cardapio.c
	gcc -c cardapio.c

run: restqueue
	./restqueue

clean:
	rm -f restqueue *.o
