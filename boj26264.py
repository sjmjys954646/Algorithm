num = int(input())
str = input()
a = str.count('security')
b = str.count('bigdata')

if(a > b):
    print('security!')
elif(a < b):
    print('bigdata?')
else :
    print('bigdata? security!')