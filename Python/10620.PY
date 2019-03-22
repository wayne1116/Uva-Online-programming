while True:
    line=input()
    line1=line.split()
    for i in range(5):
        line1[i]=int(line1[i])
    result=0;
    for i in range(5):
        result+=line1[i]
    if result==0: break
    curx=line1[1]
    cury=line1[2]
    vecx=line1[3]
    vecy=line1[4]
    flag=True
    for i in range(2*line1[0]):
        if curx%line1[0]!=0 and cury%line1[0]!=0:
            if int(curx/line1[0])%2==0 and int(cury/line1[0])%2==1:
                print('After {0} jumps the flea lands at ({1}, {2}).'.format(i,curx,cury))
                flag=False
                break
            elif int(curx/line1[0])%2==1 and int(cury/line1[0])%2==0:
                print('After {0} jumps the flea lands at ({1}, {2}).'.format(i,curx,cury))
                flag=False
                break
        curx+=vecx;
        cury+=vecy;
    if flag: print('The flea cannot escape from black squares.')
