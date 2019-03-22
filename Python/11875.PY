a=int(input())
age=[]
k=1
while a>0:
    line=input()
    num=line.split()
    for i in range(len(num)):
        num[i]=int(num[i])
    n=int(num[0]/2)
    age.clear()
    for i in range(10):
        age.append(0)
    for i in range(1,num[0]+1):
        age[num[i]-11]+=1
    accum=0
    j=0
    while j<10:
        accum+=age[j]
        if accum>n: break
        j+=1
    print('Case {0}: {1}'.format(k,j+11))
    k+=1
    a-=1
