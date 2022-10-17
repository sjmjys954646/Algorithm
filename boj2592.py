sum = 0
arr = [0] * 1001

for i in range(10):
    a = int(input())
    sum+=a
    arr[a]+=1

maxi = -1
max = 0
for i in range(1001) :
    if max < arr[i] :
        max = arr[i]
        maxi = i

print(sum//10)
print(maxi)
