for _ in range(int(input())):
    ans = False
    data = input().split(' ')
    a = int(data[0])
    b = int(data[2])
    c = int(data[4])
    if data[1] == '+' :
        if a + b == c :
            ans = True
    elif data[1] == '-' :
        if a - b == c :
            ans = True
    elif data[1] == '*':
        if a * b == c :
            ans = True
    else:
        if a // b == c :
            ans = True
    if ans :
        print("correct")
    else :
        print("wrong answer")