a=int(input())
case=1
while a>0:
    line1=input()
    line2=input()
    line1=line1.split()
    line2=line2.split()
    year1=int(line1[2])
    year2=int(line2[2])
    if line1[0]=='January' or line1[0][0]=='F':
        year1-=1
    if line2[0]=='January':
        year2-=1
    if line2[0][0]=='F' and line2[1]!='29,':
        year2-=1
    year=int(year2/4)-int(year2/100)+int(year2/400)-int(year1/4)+int(year1/100)-int(year1/400)
    print('Case {0}: {1}'.format(case,year))
    a-=1
    case+=1
