import sys
a=int(input())
count=[]
while a>0:
    line=sys.stdin.readline();
    line=line.lower()
    count.clear()
    for i in range(26):
        count.append(0)
    max=0
    for i in line:
        if i>='a' and i<='z':
            count[ord(i)-97]+=1
            if max<count[ord(i)-97]:
                max=count[ord(i)-97]
    for i in range(26):
        if max==count[i]:
            print(chr(i+97),end='')
    print()
    a-=1
