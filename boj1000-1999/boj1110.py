### ���� �Է�
ipt = int(input())
cycle = 0
### ó��
newNum = ipt
while(True) :
    newNum = newNum%10 * 10 + (newNum % 10 + newNum//10)%10
    cycle+=1
    if newNum == ipt :
        break
### ���
print(cycle)
