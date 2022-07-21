

n = int(input())
ans = 0
max_ = 0

for i in range(n):
    aux_a = int(input())
    aux_b = int(input())
    resp = (aux_a ^ aux_b)
    if (max_ < resp):
        max_ = resp
        ans = i

print(ans+1)
print()