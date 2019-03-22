import sys
number=sys.stdin.readline()
number=int(number)
for i in range(number):
    line=sys.stdin.readline()
    line1=line.split()
    for j in range(len(line1)):
        line1[j]=int(line1[j])
    if line1[0]==line1[1]:
        print('=')
    elif line1[0]>line1[1]:
        print('>')
    else:
        print('<')

