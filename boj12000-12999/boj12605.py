from collections import deque
import string

testcase = int(input())

for i in range(0,testcase):
    dq = deque()
    arr = input().split()
    for e in arr :
        dq.append(e)
    arr = ""
    while(len(dq)):
        arr+=((dq.pop()) + " ")
    print(f"Case #{i+1}: {arr}")
    
        
