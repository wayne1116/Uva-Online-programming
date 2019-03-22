a=int(input())
k=1
while a>0:
    n=int(input())
    line=input()
    num=line.split()
    for i in range(n):
        num[i]=int(num[i])
    high=0
    low=0
    for i in range(1,n):
        if num[i]-num[i-1]>0:
            high+=1
        elif num[i]-num[i-1]<0:
            low+=1
    print('Case {0}: {1} {2}'.format(k,high,low))
    k+=1
    a-=1
