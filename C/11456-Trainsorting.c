#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int a, n, i, j;
    int len;
    int result;
    int left, right, middle;
    int arr[4096];
    int ans[2048];
    
    scanf("%d", &a);
    while(a--){
        scanf("%d", &n);
        if(n==0){
            printf("0\n");
            continue;
        }
        memset(arr, 0, sizeof(arr));
        memset(ans, 0, sizeof(ans));
        for(i=0; i<n; i++){
            scanf("%d", &arr[i+n]);
            arr[n-i-1]=arr[i+n];
        }

        ans[0]=arr[0];
        len=0;
        for(i=1; i<2*n; i++){
            if(arr[i]>ans[len])
                ans[++len]=arr[i];
            else{
                for(j=0; j<=len; j++){
					if(arr[i]<=ans[j]){
						ans[j]=arr[i];
						break;
					}
				}
            }
        }
        printf("%d\n", len+1);
    }
    return 0;
}
