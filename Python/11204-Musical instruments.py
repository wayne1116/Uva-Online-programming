#!/usr/bin/python
import sys
a=int(sys.stdin.readline())

while a>0:
    line=sys.stdin.readline()
    line1=line.split()
    M=int(line1[0])
    N=int(line1[1])
    temp=[]
    for i in range(N):
        line=sys.stdin.readline()
        line1=line.split()
        temp.append(line1)
    result=1
    for i in range(M):
        mul=0
        for j in range(N):
            if temp[j][i]=='1':
                mul+=1
        if mul>0:
            result*=mul
    print(result)
    temp.clear()
    a-=1
