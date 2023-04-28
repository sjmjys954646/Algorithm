testcase = int(input())
for _ in range(testcase) :
    arr = input().split()
    if(arr[0] == 'Simon' and arr[1] == 'says') :
        print('',*arr[2:])
