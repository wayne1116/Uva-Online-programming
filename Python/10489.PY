a=int(input())
while a>0:
    line=input()
    num=line.split()
    for i in range(2):
        num[i]=int(num[i])
    total=0
    for i in range(num[1]):
        line=input()
        num1=line.split()
        mul=1
        for j in range(int(num1[0])):
            mul*=int(num1[j+1])
        total+=mul
    print(total%num[0])
    a-=1
