import sys
while True:
    line=sys.stdin.readline()
    line1=line.split()
    count=int(line1[0])
    if count==0:
        break;
    count=int(len(line1[1])/count)
    for i in range(0,len(line1[1]),count):
        j=i+count-1
        k=i
        while j>=k:
            print(line1[1][j],end='')
            j-=1
    print()
