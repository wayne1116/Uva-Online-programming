def gcd(a,b):
    if b==0:
        return a
    return gcd(b,a%b)
a=int(input())
for i in range(a):
    line1=input()
    line2=input()
    mul=2**(len(line1)-1)
    sum1=0
    for j in range(0,len(line1)):
        if line1[j]=='1':
            sum1+=mul
        mul=int(mul/2)
    mul=2**(len(line2)-1)
    sum2=0
    for j in range(0,len(line2)):
        if line2[j]=='1':
            sum2+=mul
        mul=int(mul/2)
    print('Pair #{0}: '.format(i+1),end='')
    if gcd(sum1,sum2)==1:
        print('Love is not all you need!')
    else:
        print('All you need is love!')
