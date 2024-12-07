#include<iostream>
#include<string>
#include<algorithm>
#define MAX 50
#define INF INT32_MAX
using namespace std;
char chess[MAX+1][MAX+1]={};
char ansChessMap[2][MAX+1][MAX+1]={};
int N,M;
void fill(int n){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(i==0 && j==0) continue;
            if(j==0){
                if(ansChessMap[n][i-1][j] == 'B'){
                    ansChessMap[n][i][j] = 'W';
                }else{
                    ansChessMap[n][i][j] = 'B';
                }
            }else{
                if(ansChessMap[n][i][j-1] == 'B'){
                    ansChessMap[n][i][j] = 'W';
                }else{
                    ansChessMap[n][i][j] = 'B';
                }
            }
        }
    }
}

int check(int type,int n,int m){
    int sum = 0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(chess[i+n][j+m] != ansChessMap[type][i][j]) sum++;
        }
    }

    return sum;
}

int main()
{
    int ans=INF;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        cin>>chess[i];
    }

    ansChessMap[0][0][0] = 'W';
    ansChessMap[1][0][0] = 'B';

    fill(0);
    fill(1);

    for(int i=0;i<2;i++){
        for(int j=0;j<N-7;j++){
            for(int k=0;k<M-7;k++){
                ans = min(ans,check(i,j,k));
            }
        }
    }

    cout<<ans;
    return 0;
}