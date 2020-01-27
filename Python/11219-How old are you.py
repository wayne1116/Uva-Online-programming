#!/usr/bin/python
import sys
a=int(sys.stdin.readline())
b=1
while b<=a:
    line=sys.stdin.readline()
    line=sys.stdin.readline()
    line1=line.split('/')
    line=sys.stdin.readline()
    line2=line.split('/')
    for i in range(3):
        line1[i]=int(line1[i])
        line2[i]=int(line2[i])
    result=line1[2]-line2[2]
    if line1[1]<line2[1]: result-=1
    elif line1[1]==line2[1] and line1[0]<line2[0]:result-=1
    print('Case #{0}: '.format(b),end='')
    if result<0: print('Invalid birth date')
    elif result>130:print('Check birth date')
    else: print(result)
    b+=1
