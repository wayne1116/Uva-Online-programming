#!/usr/bin/python
import sys
while True:
    line=sys.stdin.readline()
    line1=line.split()
    temp=0
    for i in range(len(line1)):
        line1[i]=int(line1[i])
        temp+=line1[i]
    if temp==0:
        break
    temp1=abs(line1[0]-line1[2])
    temp2=abs(line1[1]-line1[3])
    if temp1==0 and temp2==0:
        print('0')
    elif temp1==temp2 or temp1==0 or temp2==0:
        print('1')
    else:
        print('2')
