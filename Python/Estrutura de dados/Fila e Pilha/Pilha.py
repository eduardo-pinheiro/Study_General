class Pilha:
    __pilha = []

    def empilha( self, n ):
        self.__pilha.append( n )

    def vaziap( self ):
        return  True if self.__pilha == [] else False

    def desempilha( self ):
        return self.__pilha.pop() 

    def topo( self ):
        return self.__pilha[-1]