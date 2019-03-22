#include<stdio.h>
#include<stdlib.h>
#define swap(x,y,z) ((z)=(x),(x)=(y),(y)=(z))
#define min(x,y) ((x)>(y)?(y):(x))
#define max(x,y) ((x)>(y)?(x):(y))
int main()
{
	int a=0;
	double rx1, rx2, ry1, ry2, x1, x2, y1, y2;
	double m, b, temp1, temp2, temp3, temp4, temp;
	double minx, miny, maxx, maxy;
	scanf("%d",&a);
	while(a--){
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&rx1,&ry1,&rx2,&ry2);
		if(rx1>rx2) swap(rx1,rx2,temp);
		if(ry1>ry2) swap(ry1,ry2,temp);
		if(x1-x2==0){
			if(x1>=rx1 && x1<=rx2 && !((y1>ry2 && y2>ry2)||(y1<ry1 && y2<ry1))) printf("T\n");
			else printf("F\n");
		}
		else if(y1-y2==0){
			if(y1>=ry1 && y1<=ry2 && !((x1>rx2 && x2>rx2)||(x1<rx1 && x2<rx2))) printf("T\n");
			else printf("F\n");
		}
		else if(x1>=rx1 && x1<=rx2 && y1>=ry1 && y1<=ry2) printf("T\n");
		else if(y2>=ry1 && y2<=ry2 && x2>=rx1 && x2<=rx2) printf("T\n");
		else{
			m=(y1-y2)/(x1-x2);
			b=y1-m*x1;
			temp1=m*rx1+b;
			temp2=m*rx2+b;
			temp3=(ry1-b)/m;
			temp4=(ry2-b)/m;
			minx=min(x1,x2); maxx=max(x1,x2);
			miny=min(y1,y2); maxy=max(y1,y2);
			if((temp1>=ry1 && temp1<=ry2 && temp1>=miny && temp1<=maxy)||(temp2>=ry1 && temp2<=ry2 && temp2>=miny && temp2<=maxy))printf("T\n");
			else if((temp3>=rx1 && temp3<=rx2 && temp3>=minx && temp3<=maxx)||(temp4>=rx1 && temp4<=rx2 && temp4>=minx && temp4<=maxx)) printf("T\n");
			else printf("F\n");
		}
	}
	return 0;
}
