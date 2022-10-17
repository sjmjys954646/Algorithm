N = int(input())
arr = list(map(int,input().split()))
count = [0]*204
for i in arr :
    count[i+100]+=1
v = int(input())
print(count[v+100])

