from collections import deque

num = int(input())

arr = []    
p = 1
order = map(int,input().split())
for i in order:
    arr.insert(i,p)
    p+=1
arr.reverse()
for i in arr:
    print(str(i),end=" ")