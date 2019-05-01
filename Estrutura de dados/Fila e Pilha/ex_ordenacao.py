''' Ordene a fila[ 10, 15, 8, 5, 7, 6, 7, 8, 2, 1 ] usando apenas uma pilha, e de um print da fila ordenada no final '''

from collections import deque

fila = deque( [ 10, 15, 8, 5, 7, 6, 7, 8, 2, 1 ] )

pilha = []

while fila != deque( [] ):
    if pilha == [] or pilha[-1] >= fila[0]:
        pilha.append( fila.popleft() )
    else:
        fila.append( pilha.pop() )

while pilha != []:
    fila.append( pilha.pop() )

print( fila )

