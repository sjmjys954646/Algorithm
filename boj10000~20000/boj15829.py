M = 1234567891
r = 31

L = int(input())
    
arr = list(map(lambda x:ord(x)-ord('a') + 1,input()))

sum = 0
for i in range(len(arr)) :
    sum+=(arr[i]*pow(31,i))

print(sum%M)