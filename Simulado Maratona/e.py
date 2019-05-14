#Feito por William Otto

n = int(input())
for i in range (n):
    orc = 0
    qtd = 0
    orcv = []
    qtdv = []
    t = int(input())
    l = int(input())
    for i in range (l):
        c = int(input())
        v = int(input())
        if orc < t:
            orc += c
            qtd += v
            orcv.append(c)
            qtdv.append(v)
        if orc > t:
            teste = 0
            for k in range (len(orcv)):
                if (orc - orcv[k] + c <= t) and (v > qtdv[k]):
                    orc = orc - orcv[k] + c
                    qtd = qtd - qtdv[k] + c
                    teste = 1
                    break
            if teste == 0:
                orc -= c
                qtd -= v
    print(qtd, " ", t-orc)
