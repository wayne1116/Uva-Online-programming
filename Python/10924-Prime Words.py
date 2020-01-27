import sys
while True:
    line=sys.stdin.readline()
    if not line:
        break
    result=0
    for i in range(len(line)):
        if line[i]=='\n': break
        if ord(line[i])>=65 and ord(line[i])<=90:
            result+=ord(line[i])-38
        else:
            result+=ord(line[i])-96
    limit=int(result**0.5)+1
    state=True
    for i in range(2,limit):
        if result%i==0:
            state=False
            break
    if state:
        print('It is a prime word.')
    else:
        print('It is not a prime word.')
