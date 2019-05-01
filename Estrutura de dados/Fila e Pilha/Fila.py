from collections import deque

class Fila:
    __fila = deque()

    def enfileira( self, n ):
        self.__fila.append( n )
    
    def desenfileira( self ):
        return self.__fila.popleft()
    
    def vaziaf( self ):
        return True if self.__fila == [] else False