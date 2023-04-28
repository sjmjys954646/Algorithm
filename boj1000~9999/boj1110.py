### 변수 입력
ipt = int(input())
cycle = 0
### 처리
newNum = ipt
while(True) :
    newNum = newNum%10 * 10 + (newNum % 10 + newNum//10)%10
    cycle+=1
    if newNum == ipt :
        break
### 출력
print(cycle)
