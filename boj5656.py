i = 1
while(True):
    tmp = input().split(' ')

    if tmp[1] == 'E':
        break
    print(f'Case {i}: ',end = '')
    tmp[0] = int(tmp[0])
    tmp[2] = int(tmp[2])
    if tmp[1] == '>':
        print(str(tmp[0] > tmp[2]).lower())
    if tmp[1] == '>=':
        print(str(tmp[0] >= tmp[2]).lower())
    if tmp[1] == '<':
        print(str(tmp[0] < tmp[2]).lower())
    if tmp[1] == '<=':
        print(str(tmp[0] <= tmp[2]).lower())
    if tmp[1] == '==':
        print(str(tmp[0] == tmp[2]).lower())
    if tmp[1] == '!=':
        print(str(tmp[0] != tmp[2]).lower())

    i+=1