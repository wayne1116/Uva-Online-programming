while True:
    line=input()
    line=line.split()
    a=int(line[0])
    b=int(line[1])
    if a==-1 and b==-1:
        break
    elif a==b: print(0)
    else:
        result1=(a-b+99)%100
        result2=(b-a+99)%100
        if result1>result2:
            print(result2+1)
        else:
            print(result1+1)
