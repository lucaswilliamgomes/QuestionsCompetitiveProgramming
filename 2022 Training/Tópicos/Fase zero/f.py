def dec_to_base(num,base):  #Maximum base - 36
    base_num = ""
    while num>0:
        dig = int(num%base)
        if dig<10:
            base_num += str(dig)
        else:
            base_num += chr(ord('A')+dig-10)  #Using uppercase letters
        num //= base
    base_num = base_num[::-1]  #To reverse the string
    return base_num


for n in range(20, 10000000):
    n = str(n)
    cont = 0

    k_max = -1
    cont_max = -1

    for i in range(len(n)):
        if (n[i] == '4'):
            cont+=1

    cont_max = cont/len(n)

    #print(cont_max)

    for k in range(5, int(n)):
        cont_four = 0
        a = dec_to_base(int(n), k)
        #a = "".join(str(e) for e in a)
        for i in range(len(a)):
            if (a[i] == "4"):
                cont_four+=1
        

        if (cont_four/len(a) >= cont_max):
            k_max = k
            cont_max = cont_four/len(a)

        
        # print(a, cont_four, k)
        
    
    print(n, k_max)
