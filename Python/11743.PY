a=int(input())
while a>0:
    line=input()
    num=line.split()
    temp=''
    for i in range(len(num)):
        temp+=num[i]
    temp1=''
    result=0
    for i in range(len(temp)):
        if i%2==0:
            temp1+=str((int(temp[i])*2))
        else:
            result+=int(temp[i])
    for i in range(len(temp1)):
        result+=int(temp1[i])
    if(result%10==0):
        print('Valid')
    else:
        print('Invalid')
    a-=1
