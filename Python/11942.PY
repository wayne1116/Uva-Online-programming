a=int(input())
print('Lumberjacks:')
while a>0:
    line=input()
    num=line.split()
    for i in range(len(num)):
        num[i]=int(num[i])
    flag=True
    if num[0]>num[1]:
        flag=False
    state=True
    for i in range(2,len(num)):
        if flag==True and num[i]<num[i-1]:
            state=False
            break
        elif flag==False and num[i]>num[i-1]:
            state=False
            break
    if(state):
        print('Ordered')
    else:
        print('Unordered')
    a-=1
