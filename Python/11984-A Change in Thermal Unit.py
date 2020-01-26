a=int(input())
index=1
while a>0:
    line=input()
    num=line.split()
    for i in range(len(num)):
        num[i]=float(num[i])
    result=num[0]+num[1]*5.0/9.0;
    print('Case %d: %.2f'%(index,result))
    index+=1
    a-=1
