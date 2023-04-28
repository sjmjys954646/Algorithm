ans = 0
a,b = input().split()

for i in range(len(a)) :
    for j in range(len(b)):
        ans+=(ord(str(a)[i]) - ord('0')) * (ord(str(b)[j]) - ord('0'))

print(ans)