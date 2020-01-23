import os
def main():
	a=input()
	while a[0]!='-':
		if(a[0]=='0'):
			print(int(a,16))
		else:
			print('0x%X' % (int(a)))
		a=input()

if __name__=='__main__':
	main()
