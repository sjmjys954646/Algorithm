### ���� �Է�
hour, minute = map(int,input().split())
### ó��
minute -= 45
if minute < 0 :
    hour -=1
    minute += 60

if hour < 0 :
    hour = 23
### ���
print(f"{hour} {minute}")
