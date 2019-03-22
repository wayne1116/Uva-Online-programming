#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a=0, i=0;
	double point[8], temp1, temp2, temp3, temp4, temp5, temp6;
	double vx, vx1, vy, vy1, v1, v2, v3, v4, v5, v6, v7, v8;
	double mx1, mx2, my1, my2, b1, b2, deter, deterx, detery;
	scanf("%d",&a);
	printf("INTERSECTING LINES OUTPUT\n");
	while(a--){
		for(i=0; i<8; i++) scanf("%lf",&point[i]);
		vx=point[2]-point[0]; vy=point[3]-point[1];
		v1=point[4]-point[0]; v2=point[5]-point[1];
		v3=point[6]-point[0]; v4=point[7]-point[1];
		temp1=vx*v2-vy*v1; temp2=vx*v4-vy*v3;
		
		vx1=point[6]-point[4]; vy1=point[7]-point[5];
		v5=point[0]-point[4]; v6=point[1]-point[5];
		v7=point[2]-point[4]; v8=point[3]-point[5];
		temp3=vx1*v6-vy1*v5; temp4=vx1*v8-vy1*v7;
		temp5=temp1*temp2; temp6=temp3*temp4;
		if(temp5==0 && temp6==0) printf("LINE\n");
		else if(temp5>0 && temp6>0) printf("NONE\n");
		else{
			mx1=point[3]-point[1]; my1=-point[2]+point[0]; b1=my1*point[1]+mx1*point[0];
			mx2=point[7]-point[5]; my2=-point[6]+point[4]; b2=my2*point[5]+mx2*point[4];
			deter=mx1*my2-mx2*my1; deterx=b1*my2-b2*my1; detery=b2*mx1-b1*mx2;
			printf("POINT %.2f %.2f\n", deterx/deter, detery/deter);
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}
