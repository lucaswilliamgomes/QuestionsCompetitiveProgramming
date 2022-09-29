n = int(input())

for i in range(n):
    nome = input()
    notas = input()
    notas = notas.split(" ")

    for k in range(len(notas)):
        notas[k] = float(notas[k])
    


    if len(notas) == 1:
        a = nome + ": " + str(round(notas[0]/2, 1))
        print(a)
    elif len(notas) == 2:
        a = nome + ": " + str(round((notas[0] + notas[1] ) / 2, 1))
        print(a)
    elif len(notas) == 3:
        a = nome + ": " + str(round((notas[0] + notas[1] + notas[2] ) / 3, 1))
        print(a)
    elif len(notas) == 4:
        notas.sort()
        notas.reverse()
        a = nome + ": " + str(round((notas[0] + notas[1] + notas[2] ) / 3, 1))
        print(a)

