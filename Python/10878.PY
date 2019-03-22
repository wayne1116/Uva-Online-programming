import sys
def main():
    a=sys.stdin.readline()
    while True:
        a=sys.stdin.readline()
        if not a: break
        if a[0]=='_':
            continue
        b=a[::-1]
        mul=1
        result=0
        for i in range(len(b)):
            if b[i]==' 'or b[i]=='o':
                if b[i]=='o':
                    result+=mul
                mul*=2
        print(chr(int(result)),end='')

if __name__=='__main__':
    main()


