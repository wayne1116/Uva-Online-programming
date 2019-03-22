import os
def main():
	a=int(input())
	while a>0:
		if(a==1):
			print('0%')
		else:
			print('%d%%' %(a*100/4))
		a=int(input())
	
if __name__=='__main__':
	main()