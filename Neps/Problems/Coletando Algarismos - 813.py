n = input()

esta = 0
ans = 0

for vai in n:
  distan1 = abs (int (vai) - esta)
  if (int (vai) > esta):
    distan2 = abs (10 - int (vai) + esta)
  elif(int (vai) < esta):
    distan2 = abs (10 - esta + int (vai))
  else:
    distan2 = 0
  ans += min (distan1, distan2)  
  esta = int (int (vai))

print (ans)
