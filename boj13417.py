from collections import deque

testcase = int(input())

while testcase :
    t = int(input())
    arr = input().split()
    ans = deque()
    ans.append(arr[0])
    leftcur = arr[0]
    
    for i in range(1,len(arr)):
        if arr[i] <= leftcur :
            ans.appendleft(arr[i])
            leftcur = arr[i]
        else :
            ans.append(arr[i])
            cur = arr[i]
            
    ansstr=""
    for i in ans:
        ansstr+=i
    print(ansstr)
     
    testcase-=1
