import sys
while True:
    number=int(input())
    if number<0:
        break
    result=[]
    if number==0: print('0')
    else:
        while number>0:
            result.append(number%3)
            number=int(number/3)
        for i in range(1,len(result)+1):
            print(result[-i],end="")
        print()
    result.clear()



