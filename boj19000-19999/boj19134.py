num = int(input())

ans = 0
p = num
q = (num-2)//2

while True:
    if p == 0 :
        break

    ans+=p-q

    if q < 2 :
        p = 0
    else :
        p = (q-2)//2

    if p < 2 :
        q = 0
    else :
        q = (p-2)//2

print(ans)