#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
int dir[8][2]={{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1}};

int main()
{
    int a, i, j, k, b;
    int row, col;
    int find;
    int len;
    int x, y, tmp;
    int resultx=0, resulty=0;
    char line[64][64];
    char word[128];

    scanf("%d", &a);
    while(a--){
        scanf("%d %d", &row, &col);
        for(i=0; i<row; i++) scanf("%s", line[i]);
        for(i=0; i<row; i++){
            for(j=0; j<col; j++) line[i][j]=tolower(line[i][j]);
        }
        
        scanf("%d", &b);
        while(b--){
            scanf("%s", &word);
            len=strlen(word);
            for(i=0; i<len; i++) word[i]=tolower(word[i]);

            find=0;
            for(i=0; i<row; i++){
                for(j=0; j<col; j++){
                    if(word[0]==line[i][j]){
                        for(k=0; k<8; k++){
                            x=i;
                            y=j;
                            tmp=0;
                            while(x>=0 && x<row && y>=0 && y<col && line[x][y]==word[tmp] && tmp<len){                                
                                x+=dir[k][0];
                                y+=dir[k][1];
                                ++tmp;
                            }
                            if(tmp>=len){
                                find=1;
                                resultx=i;
                                resulty=j;
                                break;
                            }
                        }
                        if(find) break;
                    }
                }
                if(find) break;
            }
            printf("%d %d\n", resultx+1, resulty+1);
        }
        if(a) printf("\n");
    }
    return 0;
}
