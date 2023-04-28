for _ in range(int(input())) :
    N,M = map(int,input().split())
    array = [[0]*M for i in range(N)]
    for i in range(N) :
        s = list(input())
        for j in range(len(s)) :
            array[i][j] = s[j]
    
    for i in range(N) :
        for j in range(len(s)-1,-1,-1) :
            print(array[i][j],end='')
        print('\n',end='')
    