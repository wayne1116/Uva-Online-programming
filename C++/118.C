#include<stdio.h>
#include<stdlib.h>
int main()
{
		char line[128], line1[1024], *ptr, dir;
		int x=0, y=0, initx=0, inity=0, i=0, j=0, dirnumber=0, incx=0, incy=0, state=0, flag[100][100];
		fgets(line,128,stdin);
		ptr=line;
		x=atoi(ptr);
		while(*ptr){
				if(*ptr==' '){
						ptr++;
						y=atoi(ptr);
						break;
				}
				ptr++;
		}
		for(i=0; i<=x; i++)
				for(j=0; j<=y; j++)
						flag[i][j]=0;
		
		while(fgets(line,128,stdin)!=NULL){
				ptr=line;
				initx=atoi(ptr); i=0;
				while(*ptr){
						if(*ptr==' ' && i==0){
								inity=atoi(ptr);
								i++;
						}
						else if(*ptr==' ' && i==1){
								ptr++;
								dir=*ptr;
								break;
						}
						ptr++;
				}
				if(dir=='N')
						dirnumber=0;
				else if(dir=='E')
						dirnumber=90;
				else if(dir=='S')
						dirnumber=180;
				else
						dirnumber=270;
				fgets(line1, 1024, stdin);
				ptr=line1;
				state=0;
				while(*ptr){
						if(*ptr=='L'){
								if(dirnumber==0)
										dirnumber=270;
								else
										dirnumber-=90;
								if(dirnumber==0)
										dir='N';
								else if(dirnumber==90)
										dir='E';
								else if(dirnumber==180)
										dir='S';
								else
										dir='W';
						}
						else if(*ptr=='R'){
								dirnumber=(dirnumber+90)%360;
								if(dirnumber==0)
										dir='N';
								else if(dirnumber==90)
										dir='E';
								else if(dirnumber==180)
										dir='S';
								else
										dir='W';
						}
						else if(*ptr=='F'){
								incx=incy=0;
								if(dir=='N')
										incy=1;
								else if(dir=='E')
										incx=1;
								else if(dir=='S')
										incy=-1;
								else
										incx=-1;
								if(initx+incx<=x && inity+incy<=y && initx+incx>=0 && inity+incy>=0){
										initx+=incx;
										inity+=incy;
								}
								else{
										if(flag[initx][inity]==0){
											state=1;
											flag[initx][inity]=1;
											break;
										}
								}
						}
						ptr++;
				}
				printf("%d %d %c", initx, inity, dir);
				if(state)
						printf(" LOST");
				printf("\n");
		}
		return 0;
}
