import sys
while True:
    a=int(input())
    if a==0: break
    line=input()

    result=2147483647
    res=2147483647
    phr=2147483647
    for i in range(a):
        if line[i]=='Z':
            result=0
            break
        elif line[i]=='R':
            if result>abs(i-phr):
                result=abs(i-phr)
            res=i
        elif line[i]=='D':
            if result>abs(i-res):
                result=abs(i-res)
            phr=i
    print(result)
