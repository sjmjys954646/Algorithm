num = int(input())
a = input()
b = input()
av = [0]*30
bv = [0]*30

for i in range(num) :
    av[ord(a[i]) - ord('a')]+=1
    bv[ord(b[i]) - ord('a')]+=1
    

check = True

for i in range(30) :
    if av[i] != bv[i] :
        check = False
    

if a[0] != b[0] :
    check = False
if a[num-1] != b[num-1] :
    check = False

for i in ['a','e','i','o','u']:
    a = a.replace(i,'')
    b = b.replace(i,'')
    
if a!= b:
    check = False

if check :
    print("YES")
else :
    print("NO")
   
