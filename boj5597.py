arr = []
for _ in range(28) :
    arr.append(int(input()))
hubo = []
for i in range(1,31) :
    if i not in arr :
        hubo.append(str(i))

print(hubo[0])
print(hubo[1])
