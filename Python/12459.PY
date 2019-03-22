result=[1,2]
for i in range(2,80):
    result.append(result[i-1]+result[i-2])
while True:
    a=int(input())
    if a==0:
        break
    print(result[a-1])
