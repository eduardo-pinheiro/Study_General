class Binario:
    __binario = []
    __decimal = 0.00
    __bits = 0 
    
    ''' Obriga a inicialização da classe passando os atributos __binario e __bits
    def __init__(self,binario,bit):
        ___binario = binario
        ___bits = bit    
    '''
    def setDecimal(self,decimal):
        self.__decimal = decimal
    
    def setBinario(self,binario):
        self.__binario = binario
    
    def setBits(self,bits):
        self.__bits = bits

    # Converte valor depois da virgula em decimal
    def __decimalEmBinario(self, decimal, bits):
        binario = []
        for i in range(bits):
            decimal *= 2
            if ( decimal < 1 ):
                binario.append(0)
            else:
                binario.append(1)
                decimal -=  1
        return binario

    # Converte binario depois da virgula em real
    def __binarioEmDecimal(self, binario):
        decimal = 0
        y = 1
        for l in binario:
            y /= 2 
            if l == 1:
                decimal += y    
        return decimal

    # Incrementa 1 no binário
    def __incremento(self, binario):
        i = 0
        flag = False
        binario.reverse()
        for l in binario:
            if l == 0:
                binario[i] = 1
                flag = True
                break
            else:
                binario[i] = 0
            i += 1
        if flag == False:
            binario.append(1)
        binario.reverse()
        return binario    

    # Retorna o erro porcentual à menor da converção do numero depois da virgula em binário
    def __erroMenor(self, decimal, bits):
        binario = self.__decimalEmBinario(decimal, bits)
        erroDecimal = self.__binarioEmDecimal(binario)
        erroPorcentual = 100 - ( (erroDecimal * 100) / decimal )
        return erroPorcentual
    
    # Retorna o erro porcentual à maior da converção do numero depois da virgula em binário
    def __erroMaior(self, decimal, bits):
        binario = self.__decimalEmBinario(decimal, bits)
        binario = self.__incremento(binario)
        erroDecimal = self.__binarioEmDecimal(binario)
        erroPorcentual = ( (erroDecimal * 100) / decimal ) -100
        return erroPorcentual    

    def getDecimalEmBinario(self):
        return self.__decimalEmBinario(self.__decimal, self.__bits)
    

    def getBinarioEmDecimal(self):
        return self.__binarioEmDecimal(self.__binario)
    

    def getIncremento(self):
        return self.__incremento(self.__binario)

    def getErroMenor(self):
        return self.__erroMenor(self.__decimal, self.__bits)

    def getErroMaior(self):
        return self.__erroMaior(self.__decimal, self.__bits)
        