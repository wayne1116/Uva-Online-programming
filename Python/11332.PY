#!/usr/bin/python
import sys
while True:
    line=input()
    if line=='0':break
    line1=list(line)
    temp=0
    for i in range(len(line1)):
        temp+=int(line1[i])
    while temp>9:
        temp1=0
        while temp>0:
            temp1+=temp%10
            temp=int(temp/10)
        temp=temp1
    print(temp)


