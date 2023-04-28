maxi = -1
ans = -1

for _ in range(5) :
    arr = map(int,input().split())
    sum = 0
    for t in arr :
        sum+=t
    if ans < sum :
        maxi = _ + 1
        ans = sum

print(f'{maxi} {ans}')