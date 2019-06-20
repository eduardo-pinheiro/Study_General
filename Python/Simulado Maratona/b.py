#Feito por Gustavo Borges

Qntd_veiculos = int(input())
while (Qntd_veiculos != -1) :
    veic_escolhido = 1
    for i in range(30) :
        veic_escolhido+=1
        if (veic_escolhido > Qntd_veiculos) :
            veic_escolhido = 1
    print(veic_escolhido)
    Qntd_veiculos = int(input())