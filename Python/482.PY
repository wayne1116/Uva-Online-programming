import sys
a=int(input())
k=0
while a>0:
    if k>0:
        print()
    ign=sys.stdin.readline()
    temp=sys.stdin.readline()
    index=temp.split()
    temp=sys.stdin.readline()
    number=temp.split()
    for i in range(len(index)):
        index[i]=int(index[i])
    for i in range(len(index)):
        for j in range(len(number)):
            if i+1==index[j]:
                print(number[j])
                break
    a-=1
    k+=1
