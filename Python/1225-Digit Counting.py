a=int(input())
result=[]
for i in range(10):
    result.append(0)
while a>0:
    b=int(input())
    for i in range(10):
        result[i]=0
    for i in range(1,b+1):
        temp=i
        while(temp>0):
            result[temp%10]+=1
            temp=int(temp/10)
    print(result[0],end='')
    for i in range(1,10):
        print(' '+str(result[i]),end='')
    print()
    a-=1
