a, b = map(int,input().split())
m = int(input())
num = list(map(int,input().split()))

num.reverse()
c = 0
j = 1
for i in num :
    c += (i*j)
    j*=a

j = 1
cut = []
for i in range(0,22) :
    cut.append(j)
    j*=b

cut.reverse()
ans = []
for i in cut :
    ans.append(c // i)
    c %= i

start = 0
for i in range(0,len(ans)) :
    if ans[i] != 0:
        start = i
        break

for i in range(start,len(ans)):
    print(ans[i],end = ' ')
