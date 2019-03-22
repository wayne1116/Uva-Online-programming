mapping={'W':64,'H':32,'Q':16,'E':8,'S':4,'T':2,'X':1}
while True:
    line=input()
    if line=='*':
        break
    result=temp=0
    for i in range(1,len(line)):
        if line[i]=='/':
            if temp==64:
                result+=1
            temp=0
        else:
            temp+=mapping[line[i]]
    print(result)
