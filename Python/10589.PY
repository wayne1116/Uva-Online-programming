import os
import sys
def main():
	input1=sys.stdin.readline()
	number=input1.split()
	for i in range(len(number)):
		number[i]=int(number[i])
	while number[0] and number[1] :
		square=number[1]*number[1]
		sum=0
		for i in range(number[0]):
			input1=sys.stdin.readline()
			temp=input1.split()
			for j in range(len(temp)):
				temp[j]=float(temp[j])
			if (temp[0]*temp[0]+temp[1]*temp[1])<=square and (temp[0]*temp[0]+(temp[1]-number[1])*(temp[1]-number[1])<=square):
				if((temp[0]-number[1])*(temp[0]-number[1])+temp[1]*temp[1]<=square and (temp[0]-number[1])*(temp[0]-number[1])+(temp[1]-number[1])*(temp[1]-number[1])<=square):
					sum+=1
		M=float(sum)
		N=float(number[0])
		print('%.5f' % (M/N*square))
		input1=sys.stdin.readline()
		number=input1.split()
		for i in range(len(number)):
			number[i]=int(number[i])
			
if __name__=='__main__':
	main()