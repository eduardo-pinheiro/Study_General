#Feito por Eduardo Pinheiro

def quantidadeSequencia( sequencias, tamanho ):
    
    dicSequencias = []
    contSequencias = []
    result = 0

    for i in range( 0, len( sequencias[0] ) - tamanho ):
        
        sequenciaAtual = sequencias[ i : i + tamanho ]
        
        if not( dicSequencias.count( sequenciaAtual ) ):
            dicSequencias.append( sequenciaAtual )
    

    for i in range( i, len( sequencias ) ):

        for j in range( 0, len( sequencias[i] ) - tamanho ):
            
            sequenciaAtual = sequencias[i][ j : j + tamanho ]
            
            if dicSequencias.count( sequenciaAtual ) and contSequencias.count( sequenciaAtual ) < i:
                contSequencias.append( sequenciaAtual )


    for sequencia in dicSequencias:
        if contSequencias.count( sequencia ) == len( sequencias ) - 1:
            result += 1
        print( contSequencias )

    return result 


sequencias = []

for i in range( 0, 3 ):
    sequencias.append( input() )

tamanho = int( input() )
 
print( quantidadeSequencia( sequencias, tamanho ) )



