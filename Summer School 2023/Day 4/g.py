import math

t = (int)(input())

EPS = 0.000001

while (t):
    b1, p1, b2, p2 = [int(x) for x in input().split()] 

    t = t - 1

    if (p1 == 0 or b1 == 1):
        ans1 = 1
    elif (b1 == 0):
        ans1 = 0
    else: 
        ans1 = p1 * math.log(b1)

    if (p2 == 0 or b2 == 1):
        ans2 = 1
    elif (b2 == 0):
        ans2 = 0;
    else:
        ans2 = p2 * (math.log(b2))

    #print(ans1, " ", ans2)

    if (abs(ans1 - ans2) < EPS):
        print("Lazy")
    elif (ans1 < ans2):
        print("Congrats")
    else:
        print("HaHa")

    
        