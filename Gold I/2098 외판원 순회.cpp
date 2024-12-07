#include<iostream>
#include<algorithm>
#include<queue>
#define INF 0xFFFFFF
#define MAX 17
using namespace std;
int W[MAX][MAX]={0,},memo[MAX][1<<16];
int N,ans=INF;
int TSP(int idx, int visit){
    if(visit==(1<<N)-1){
        if(W[idx][0]==0) return INF;
        return W[idx][0];
    }
    if(memo[idx][visit]!=-1) return memo[idx][visit];
    memo[idx][visit]=INF;
    for(int i=0;i<N;i++){
        if(W[idx][i] == 0) continue;
        if((visit & (1<<i)) == (1<<i)) continue;
       
        memo[idx][visit]=min(memo[idx][visit],TSP(i,visit | (1<<i))+W[idx][i]);
    }
    return memo[idx][visit];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++) cin>>W[i][j];
        for(int j=0;j<(1<<N);j++) memo[i][j]=-1;
    }
    cout<<TSP(0,1);
    return 0;
}