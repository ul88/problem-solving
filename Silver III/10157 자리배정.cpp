#include<stdio.h>
#define MAX 1000
int arr[MAX+1][MAX+1]={0,};
int main()
{
    int C,R,K; // R : row, C : col -> 90도 변환 -> C: row , R : col
    scanf("%d %d %d",&C,&R,&K);
    if(C*R < K){
        printf("0");
        return 0;
    }

    int dir = 0; // 방향 : 오른쪽 -> 아래 -> 왼쪽 -> 위
    int a=1, b=1, cnt = 1;
    arr[a][b]=cnt++;
    int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
    while(cnt <= C*R){
        if(a+dx[dir] >=1 && a+dx[dir] <= C && b+dy[dir]>=1 && b+dy[dir] <= R && arr[a+dx[dir]][b+dy[dir]]==0){
            arr[a+dx[dir]][b+dy[dir]]=cnt++;
            a+=dx[dir],b+=dy[dir];
        }else{
            dir++;
            dir%=4;
        }
    }

    for(int i=1;i<=C;i++){
        for(int j=1;j<=R;j++){
            if(arr[i][j] == K){
                printf("%d %d",i,j);
                return 0;
            }   
        }
    }
    return 0;
}