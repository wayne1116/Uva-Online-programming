#!/usr/bin/python
import sys
a=int(input())
list1=[]
while a>0:
    n=int(input())
    temp=sys.stdin.readline()
    number=temp.split()
    sum=0
    for i in range(n):
        number[i]=int(number[i])
        sum+=number[i]
    location=int(sum/n)
    number.sort()
    result=location-number[0]
    for i in range(1,len(number)):
        result+=number[i]-number[i-1]
    result+=number[n-1]-location
    print(result)
    a-=1

