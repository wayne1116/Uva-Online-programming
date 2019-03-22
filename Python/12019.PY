a=int(input())
day=[0,6,2,2,5,7,3,5,1,4,6,2,4]
result=['Sunday','Monday','Tuesday','Wednesday','Thursday','Friday','Saturday']
while a>0:
    line=input()
    num=line.split()
    for i in range(len(num)):
        num[i]=int(num[i])
    start=day[num[0]]
    cycle=num[1]-1
    start=(start+cycle)%7
    print(result[start])
    a-=1
