a=int(input())
while a>0:
    temp=input()
    num=temp.split()
    for i in range(len(num)):
        num[i]=int(num[i])
    empty=num[0]+num[1]
    result=0
    while empty>=num[2]:
        result+=int(empty/num[2])
        empty=int(empty/num[2])+empty%num[2]
    print(result)
    a-=1
