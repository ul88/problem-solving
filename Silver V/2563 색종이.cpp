#include<stdio.h>
int main()
{
    int arr[101][101]={};
    int N,ans=0;
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        int x, y;
        scanf("%d %d",&x,&y);
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                if(!arr[x+j][y+k]) ans++;
                arr[x+j][y+k] = 1;
            }
        }
    }

    printf("%d",ans);
    return 0;
}