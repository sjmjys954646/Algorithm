T = int(input())
main = input()
mainlen = len(main)
for i in range(0,T-1):
    st = input()
    for t in range(0,mainlen):
        if(main[t]!=st[t]):
            li = list(main)
            li[t] = '?'
            main = ''.join(li)
print(main)
    
