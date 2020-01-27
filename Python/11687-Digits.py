import sys
while True:
    line=sys.stdin.readline()
    line=line.strip('\n')
    if line=='END':
        break
    i=1
    len2=line
    while True:
        len1=len2
        len2=str(len(len1))
        if len1==len2:
            print(i)
            break
        i+=1
