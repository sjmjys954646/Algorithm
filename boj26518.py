b,c,a1,a2 =  map(int,input().split())

v = [a1,a2]
index = 2
bef = a2/a1
cur = bef

while True:
    an = b*v[index-1] + c*v[index-2]
    ann = v[index-1]

    cur = an/ann

    if(abs(cur - bef) < 0.00000001):
        break

    v.append(an)
    index+=1
    bef = cur

print(cur)


