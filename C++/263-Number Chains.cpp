#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;
bool cmp1(char &x, char &y)
{
	return x>y;
}
bool cmp2(char &x, char &y)
{
	return y>x;
}
int main()
{
	int a=0, count=0, i=0, temp1=0, len=0, state=0, number1=0, number2=0;
	char temp2[16], temp3[16];
	int temp[1024], j=0;
	while(scanf("%d",&a)!=EOF && a){
		printf("Original number was %d\n", a);
		count=0;
		while(1){
			temp1=a; len=0;
			while(temp1>0){
				temp2[len++]=(temp1%10)+48;
				temp1/=10;
			}
			temp2[len]='\0';
			for(i=0; i<len; i++) temp3[i]=temp2[i];
			temp3[len]='\0';
			sort(temp2,temp2+len,cmp1);
			sort(temp3,temp3+len,cmp2);
			number1=atoi(temp2);
			number2=atoi(temp3);
			printf("%d - %d = %d\n", number1, number2, number1-number2);
			a=number1-number2;
			state=0;
			for(i=0; i<count; i++){
				if(temp[i]==a){
					state=1;
					break;
				}
			}
			if(!state) temp[count++]=a;
			else{
				printf("Chain length %d\n", count+1);
				break;
			}
		}
		printf("\n");
	}
	return 0;
}

/* other method

#include<iostream>
#include<set>
using namespace std;
int main()
{
    int number;
    int count[10];
    while(cin >> number){
        if(number==0)
            break;
        cout << "Original number was " << number << endl;
        set<int> set1;
        int level=0;
        while(true){
            for(int i=0; i<10; i++)
                count[i]=0;
            while(number>0) {
                ++count[number%10];
                number/=10;
            }
            int number1=0;
            for(int i=0; i<10; i++) {
                for(int j=0; j<count[i]; j++)
                    number1=number1*10+i;
            }

            int number2=0;
            for(int i=9; i>=0; i--) {
                for(int j=0; j<count[i]; j++)
                    number2=number2*10+i;
            }
            number=number2-number1;
            ++level;
            cout << number2 << " - " << number1 << " = " << number << endl;
            if(set1.count(number)==0)
                set1.insert(number);
            else break;
        } 

        cout << "Chain length " << level << endl << endl;
    }
    return 0;
}


/*
