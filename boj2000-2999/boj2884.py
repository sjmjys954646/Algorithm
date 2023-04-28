### 변수 입력
hour, minute = map(int,input().split())
### 처리
minute -= 45
if minute < 0 :
    hour -=1
    minute += 60

if hour < 0 :
    hour = 23
### 출력
print(f"{hour} {minute}")
