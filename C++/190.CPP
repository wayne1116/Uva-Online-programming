#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	double x1=0, x2=0, x3=0, y1=0, y2=0, y3=0;
	double a1=0, b1=0, a2=0, b2=0;
	double x=0, y=0, r=0;
	double temp=0;
	while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3)!=EOF){
		if(y2-y3!=0){
			a1=-(x2-x3)/(y2-y3);
			b1=(x2*x2+y2*y2-x3*x3-y3*y3)/2/(y2-y3);
		}
		if(y1-y3!=0){
			a2=-(x1-x3)/(y1-y3);
			b2=(x1*x1+y1*y1-x3*x3-y3*y3)/2/(y1-y3);
		}
		if(y2-y3!=0 && y1-y3!=0){
			x=(b2-b1)/(a1-a2);
			y=a1*x+b1;
		}
		else{
			if(y2-y3==0){
				x=(x2+x3)/2;
				y=a2*x+b2;
			}
			else{
				x=(x1+x3)/2;
				y=a1*x+b1;
			}
		}
		temp=(x-x1)*(x-x1)+(y-y1)*(y-y1);
		r=sqrt(temp);
		if(x>0) printf("(x - %.3f)^2 + ",x);
		else if(x<0)printf("(x + %.3f)^2 + ",-x);
		else printf("x^2 + ");
		
		if(y>0) printf("(y - %.3f)^2",y);
		else if(y<0)printf("(y + %.3f)^2",-y);
		else printf("y^2");
		printf(" = %.3f^2\n",r);
		
		printf("x^2 + y^2 ");
		if(x>0) printf("- %.3fx ",2*x);
		else if(x<0)printf("+ %.3fx ",2*-x);
		if(y>0) printf("- %.3fy ",2*y);
		else if(y<0) printf("+ %.3fy ",2*-y);
		temp=x*x+y*y-temp;
		if(temp<0) printf("- %.3f",-temp);
		else printf("+ %.3f",temp);
		printf(" = 0\n\n");
	}
	return 0;
}
