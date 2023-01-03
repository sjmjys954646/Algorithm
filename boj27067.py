num = int(input())
arr1 = list(map(int,input().split()))
arr2 = list(map(int,input().split()))
arr3 = list(map(int,input().split()))

newarr = []

for i in range(num-1,-1,-1):
    if arr1[i] == arr2[i] and arr3[i] == arr2[i] and arr1[i] == arr3[i] :
        continue

    if(arr1[i] == arr2[i]) :
        p = arr1[i]
        idx = i
        while True :
            if arr3[idx] == p :
                for j in range(num) :
                    if j == idx :
                        continue
                    newarr.append(arr3[j])
                newarr.insert(i,p)
                break
            idx-=1
        break
    elif (arr2[i] == arr3[i]):
        p = arr2[i]
        idx = i
        while True:
            if arr1[idx] == p:
                for j in range(num):
                    if j == idx:
                        continue
                    newarr.append(arr1[j])
                newarr.insert(i, p)
                break
            idx -= 1
        break
    elif (arr1[i] == arr3[i]):
        p = arr1[i]
        idx = i
        while True:
            if arr2[idx] == p:
                for j in range(num):
                    if j == idx:
                        continue
                    newarr.append(arr2[j])
                newarr.insert(i, p)
                break
            idx -= 1
        break

for i in newarr :
    print(i,end = ' ')