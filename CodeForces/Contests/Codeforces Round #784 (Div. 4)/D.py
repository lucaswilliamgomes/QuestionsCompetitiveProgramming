t = int(input())

for x in range(t):
    n = int(input())
    s = input()
    lists = s.split('W')
    flag = True
    for l in lists:
        r = "R" in l
        b = "B" in l
        # XOR OPERATION
        if (r ^ b):
            flag = False

    print("YES" if flag else "NO")
        
    
    
