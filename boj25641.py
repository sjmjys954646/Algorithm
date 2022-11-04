Tarr = [0]*101
Sarr = [0]*101

N = int(input())
soTuck = input()

for i in range(N-1,-1,-1) :
    if soTuck[i] == 's' :
        Sarr[i]=Sarr[i+1]+1
    else :
        Sarr[i]=Sarr[i+1]

for i in range(N - 1, -1, -1):
    if soTuck[i] == 't':
        Tarr[i] = Tarr[i + 1] + 1
    else:
        Tarr[i] = Tarr[i + 1]

ans = ""
for i in range(0,N) :
    if Sarr[i] == Tarr[i] :
        ans = soTuck[i:]
        break
print(ans)
