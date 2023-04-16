N = int(input())
arr = [0] * 36
arr[0] = 1
arr[1] = 1
arr[2] = 2

for i in range(3,N+1) :
    sum = 0
    for j in range(0,i) :
        sum += arr[j] * arr[i-j - 1]
    arr[i] = sum

print(arr[N])
        
