import sys
while True:
    line=sys.stdin.readline()
    line=line.strip('\n')
    if line[0]=='0' and len(line)==1:
        break
    result1=0
    result2=0
    state=True
    for i in range(len(line)):
        if line[i]>='0' and line[i]<='9':
            if state:
                start=i
                state=False
            else:
                end=i
            if i%2==1:
                result2+=ord(line[i])-48
            else:
                result1+=ord(line[i])-48
    if abs(result1-result2)%11==0:
        print('{0} is a multiple of 11.'.format(line[start:end+1]))
    else:
        print('{0} is not a multiple of 11.'.format(line[start:end+1]))

