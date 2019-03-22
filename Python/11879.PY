while True:
    a=input()
    if a[0]=='0':
        break
    result=0
    size=len(a)
    while True:
        end=size
        size=size-16
        if(size<=0):
            break
        result+=int(a[size:end])
    result+=int(a[0:end])
    if result%17==0:
        print(1)
    else:
        print(0)
