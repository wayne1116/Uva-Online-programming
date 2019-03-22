a=int(input())
for i in range(a):
	start=int(input())
	end=int(input())
	result=0
	for j in range(start,end+1):
		if(j%2):
			result+=j
	print('Case %d: %d' %(i+1,result))