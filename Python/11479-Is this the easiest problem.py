import sys
if __name__=='__main__':
    a=int(input())
    j=1
    while a>0:
        temp=sys.stdin.readline()
        num=temp.split()
        for i in range(len(num)):
            num[i]=int(num[i])
        num.sort()
        print('Case {0}: '.format(j),end='')
        if num[0]+num[1]>num[2] and num[1]+num[2]>num[0] and num[0]+num[2]>num[1]:
            if num[0]==num[1] and num[0]==num[2]:
                print('Equilateral')
            elif num[0]==num[1] or num[1]==num[2]:
                print('Isosceles')
            else:
                print('Scalene')
        else:
            print('Invalid')
        j+=1
        a-=1
