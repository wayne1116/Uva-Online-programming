#!/usr/bin/python
import sys
a=int(input())
while a>0:
    n=int(input())
    line=sys.stdin.readline()
    number=line.split()
    for i in range(n):
        number[i]=int(number[i])
    number.sort(reverse=True)
    result=0
    for i in range(2,n,3):
        result+=number[i]
    print(result)
    a-=1
