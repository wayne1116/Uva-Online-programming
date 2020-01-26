a=int(input())
while a>0:
    line=input()
    num=line.split()
    for i in range(3):
        num[i]=int(num[i])
    if num[0]+num[1]>num[2] and num[0]+num[2]>num[1] and num[1]+num[2]>num[0]:
        print('OK')
    else:
        print('Wrong!!')
    a-=1
