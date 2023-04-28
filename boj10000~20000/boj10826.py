N = int(input())
arr = [0]*10002
arr[1] = 1

for i in range(2,10002):
    arr[i] = arr[i-1] + arr[i-2]

print(arr[N])

