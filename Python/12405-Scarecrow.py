a=int(input())
count=1
while a>0:
    num=int(input())
    line=input()
    i=0
    result=0
    while i<num:
       if line[i]=='.':
           result+=1
           i+=3
       else:
           i+=1
    print('Case {0}: {1}'.format(count,result))
    a-=1
    count+=1
