import sys
a=int(input())
while a>0:
    temp=sys.stdin.readline()
    list1=temp.split()
    for i in range(len(list1)):
        list1[i]=int(list1[i])
    if (list1[0]+list1[1])%2==0:
        team1=int((list1[0]+list1[1])/2)
        team2=int(list1[0]-team1)
        if team2<0:
            print('impossible')
        else:
            print('{0} {1}'.format(team1,team2))
    else:
        print('impossible')
    a-=1
