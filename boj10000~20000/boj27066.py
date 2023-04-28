num = int(input())
arr = list(map(int,input().split()))
sum = 0

for i in arr:
    sum+=i

arr.sort()

if(num > 1):
    print(max(sum/num,arr[-2]))
else :
    print(arr[0])