import sys
win=[]
lose=[]
j=0
while True:
    temp=sys.stdin.readline()
    if temp[0]=='0':
        break
    if j>0:
        print()
    temp1=temp.split()
    for i in range(len(temp1)):
        temp1[i]=int(temp1[i])
    win.clear()
    lose.clear()
    for i in range(temp1[0]):
        win.append(0)
        lose.append(0)
    limit=int(temp1[1]*temp1[0]*(temp1[0]-1)/2)
    for i in range(limit):
        line=sys.stdin.readline()
        line1=line.split()
        line1[0]=int(line1[0])
        line1[2]=int(line1[2])
        if line1[1]=='rock':
            if line1[3]=='paper':
                win[line1[2]-1]+=1
                lose[line1[0]-1]+=1
            elif line1[3]=='scissors':
                win[line1[0]-1]+=1
                lose[line1[2]-1]+=1
        elif line1[1]=='scissors':
            if line1[3]=='rock':
                win[line1[2]-1]+=1
                lose[line1[0]-1]+=1
            elif line1[3]=='paper':
                win[line1[0]-1]+=1
                lose[line1[2]-1]+=1
        else:
            if line1[3]=='scissors':
                win[line1[2]-1]+=1
                lose[line1[0]-1]+=1
            elif line1[3]=='rock':
                win[line1[0]-1]+=1
                lose[line1[2]-1]+=1
    for i in range(temp1[0]):
        if win[i]==0 and lose[i]==0:
            print('-')
        else:
            print('%.3f'%(win[i]/(win[i]+lose[i])))
    j+=1
