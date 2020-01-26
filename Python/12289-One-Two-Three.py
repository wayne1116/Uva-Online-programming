a=int(input())
while a>0:
    line=input()
    if len(line)==3:
        if line[0]=='o' and line[1]=='n' or line[1]=='n' and line[2]=='e' or line[0]=='o' and line[2]=='e':
            print(1)
        else:
            print(2)
    else:
        print(3)
    a-=1
