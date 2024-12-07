#include<stdio.h>
int map[21][21]={0,};
int f1(int n,int m){ // 0은 틀림 1은 맞음
    int cnt = 0;
    for(int i=1;i<5;i++){ //n,m == n,m+1 && n,m == n,m+2 && n,m+3 && n,m+4
        if(m+i > 19) break;
        if(map[n][m] == map[n][m+i]){
            cnt++;
        }
    }

    if(cnt == 4){
        if(map[n][m] == map[n][m+5] || map[n][m] == map[n][m-1]){
            return 0;
        }else{
            printf("%d\n",map[n][m]);
            printf("%d %d",n,m);
            return 1;
        }
    }
    return 0;
}
int f2(int n,int m){
    int cnt = 0;
    for(int i=1;i<5;i++){ //n,m == n,m+1 && n,m == n,m+2 && n,m+3 && n,m+4
        if(n+i > 19) break;
        if(map[n][m] == map[n+i][m]){
            cnt++;
        }
    }

    if(cnt == 4){
        if(map[n][m] == map[n+5][m] || map[n][m] == map[n-1][m]){
            return 0;
        }else{
            printf("%d\n",map[n][m]);
            printf("%d %d",n,m);
            return 1;
        }
    }
    return 0;
}
int f3(int n,int m){
    int cnt = 0;
    for(int i=1;i<5;i++){ //n,m == n,m+1 && n,m == n,m+2 && n,m+3 && n,m+4
        if(m+i > 19 || n+i > 19) break;
        if(map[n][m] == map[n+i][m+i]){
            cnt++;
        }
    }

    if(cnt == 4){
        if(map[n][m] == map[n+5][m+5] || map[n][m] == map[n-1][m-1]){
            return 0;
        }else{
            printf("%d\n",map[n][m]);
            printf("%d %d",n,m);
            return 1;
        }
    }
    return 0;
}
int f4(int n,int m){
    int cnt = 0;
    for(int i=1;i<5;i++){ //n,m == n,m+1 && n,m == n,m+2 && n,m+3 && n,m+4
        if(m-i < 1 || n+i > 19) break;
        if(map[n][m] == map[n+i][m-i]){
            cnt++;
        }
    }

    if(cnt == 4){
        if(map[n][m] == map[n+5][m-5] || map[n][m] == map[n-1][m+1]){
            return 0;
        }else{
            printf("%d\n",map[n][m]);
            printf("%d %d",n+4,m-4);
            return 1;
        }
    }
    return 0;
}

int main()
{
    for(int i=1;i<=19;i++){
        for(int j=1;j<=19;j++){
            scanf("%d",&map[i][j]);
        }
    }
    
    for(int i=1;i<=19;i++){
        for(int j=1;j<=19;j++){
            if(map[i][j]!=0){
                if(f1(i,j)){
                    return 0;
                }
                if(f2(i,j)){
                    return 0;
                }
                if(f3(i,j)){
                    return 0;
                }
                if(f4(i,j)){
                    return 0;
                }
            }
        }
    }
    printf("0");
    return 0;
}