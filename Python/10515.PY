result=[[0],[1],[2,4,8,6],[3,9,7,1],[4,6],[5],[6],[7,9,3,1],[8,4,2,6],[9,1]]
while True:
    line=input()
    num=line.split()
    if num[0]=='0' and num[1]=='0': break
    if num[1]=='0': print(1)
    else:
        num1=ord(num[0][len(num[0])-1])-48
        len1=len(result[num1])
        print(result[num1][(int(num[1])-1)%len1])



