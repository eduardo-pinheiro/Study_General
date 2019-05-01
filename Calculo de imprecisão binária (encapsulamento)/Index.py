print('\nNome: Eduardo Felipe Santos Pinheiro  RA: 18101578 \n__________________________________________________\n\n')

from Binario import Binario
bin = Binario()

x = float(input("Digite um número real entre 0 e 1: "))
while( x <= 0 or x >= 1):
    x = float(input("Valor invalido tente outro número entre 0 e 1: "))
bin.setDecimal(x)

for i in range(5,12+1):
    bin.setBits(i)
    bin.setBinario(bin.getDecimalEmBinario())
    print('\n',i,' bits \nMenor:    Binario =',bin.getDecimalEmBinario(),' |  Aproximação =',bin.getBinarioEmDecimal(),' |  Erro = %',bin.getErroMenor(),'\nMaior: Incremento =',bin.getIncremento(),' |  Aproximação =',bin.getBinarioEmDecimal(),' |  Erro = %',bin.getErroMaior(),'\n')

