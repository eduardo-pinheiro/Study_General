import re

option = ""
voters = {}

def clear():
    print('\n'*50)


def delVoter(voterAndScore):
    voter = re.search("[a-zA-Z]+", voterAndScore)
    print(voter.group())
    del voters[voter.group().lower()]

def setVoter(voterAndScore):
    voter = re.search("[a-zA-Z]+", voterAndScore)
    score = re.search("\d+", voterAndScore)
    voters[voter.group().lower()] = score.group()


def maintainVoters():
    try:
        textInput = input('')
        textInputArray = re.findall("[\w -]+", textInput)

        for voterComand in textInputArray:

            delete = re.search("(-)", voterComand)
            
            if delete:
                delVoter(voterComand)
            else:
                setVoter(voterComand)
    except:
        cicle(True)

def totalScore():
    total = 0
    for voter in voters:
        total += float(voters[voter])
    return total


def showVoters():
    total = totalScore()

    print('LISTA DE PARTICIPANTES:')
    
    for voter in voters:
        porcent = ( float(voters[voter]) / total ) * 100
        print(voter, ': ', voters[voter], ' ',"{0:.2f}%".format(porcent))

    if not voters:
        print('Não há participantes inseridos :(')


def cicle(error):   
    clear()
    print('Adicionar: <nome> <pontuação>                  ->   marcelo 10')
    print('Editar:    <nome-existente> <nova pontuação>   ->   marcelo 5')
    print('Excluir:   -<nome>                            ->   -marcelo')
    print('\nOs comandos podem ser inserido em série        ->   marcelo 10, joão 5, --marcos')
    print('________________________________________________________________________________\n')
    showVoters()
    print('\n')
    if error:
        print('!!Houve um erro de sintaxe, siga as orientações no topo e tente novamente:')
    maintainVoters()
    
    
while True:
    cicle(False)