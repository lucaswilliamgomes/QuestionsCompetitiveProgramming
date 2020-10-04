# ESTA ERRADA

n = int (input ())
all_info = input ()

if (n == 2):
  if (all_info == "A"):
    print ("0 1")
  else:
    print ("1 0")

else:
  atual_zero = 0
  menor_zero = 0
  indice_zero = 0

  for i in range(len(all_info)):
    if all_info[i] == "A":
      atual_zero += 1
    else:
      atual_zero -= 1
      if (menor_zero > atual_zero):
        menor_zero = atual_zero
        indice_zero = i

  #temos o indice correto do zero

  ans = list(range(n))

  preco = 0

  if (indice_zero == 0):
    ans[0] = 0
    for i in range (1, n):
      if (all_info[i-1] == "A"):
        preco += 1
        ans[i] = preco
      else:
        preco -= 1
        ans[i] = preco

  else:

    ans[indice_zero+1] = 0
    
    for i in range(indice_zero+2, n):

      if all_info[i-1] == "A":
        preco += 1
        ans[i] = preco
      else:
        preco -= 1
        ans[i] = preco

    preco = 0

    for i in range (indice_zero, -1, -1):
      
      if i > 0:

        if all_info[i-1] == "A":
          preco += 1
          ans[i] = preco
        else:
          if all_info[i] == "A":
            preco -= 1
            ans[i] = preco
          else:
            preco += 1
            ans[i] = preco

      elif i == 0:
        if all_info[i] == "A":
          ans[0] = preco-1
        else:
          ans[0] = preco+1


  for i in range (len(ans)):
    print (ans[i], end=" ")

