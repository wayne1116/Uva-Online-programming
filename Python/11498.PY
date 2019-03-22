import sys
while True:
    a=int(input())
    if a==0: break
    line=sys.stdin.readline()
    number=line.split()
    for i in range(2):
        number[i]=int(number[i])
    while a>0:
        line=sys.stdin.readline()
        number1=line.split()
        result=[0,0]
        for i in range(2):
            number1[i]=int(number1[i])
            result[i]=number1[i]-number[i]
        if result[0]==0 or result[1]==0:
            print('divisa')
        elif result[0]>0 and result[1]>0:
            print('NE')
        elif result[0]>0 and result[1]<0:
            print('SE')
        elif result[0]<0 and result[1]>0:
            print('NO')
        else:
            print('SO')
        a-=1
