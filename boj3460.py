for _ in range(int(input())) :
    n = int(input())
    arr = []
    index = 0
    while n > 0 :
        arr.append(n%2)
        n = n//2
    #arr.reverse()
    for i in range(len(arr)) :
        if arr[i] == 1 :
            print(i,end = ' ')
