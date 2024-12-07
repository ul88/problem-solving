#include<iostream>
#include<cmath>
#include<algorithm>
#define MAX 20
#define INF INT32_MAX
using namespace std;
int arr[MAX+1][MAX+1]={0,};
int visit[MAX+1]={0,};
int N,ans=INF;
void dfs(int n,int k){
    if(k <= 0){
        int start=0,link=0;

        for(int i=0;i<N;i++){
            for(int j=i+1;j<N;j++){
                if(visit[i] != visit[j]) continue;
                if(visit[i]){
                    start += arr[i][j] + arr[j][i];
                }else{
                    link += arr[i][j] + arr[j][i];
                }
            }
        }
        
        ans = min(ans,abs(start-link));
        return;
    }
    for(int i=n;i<N;i++){
        if(visit[i]) continue;
        visit[i] = 1;
        dfs(i,k-1);
        visit[i] = 0;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>arr[i][j];
        }
    }

    dfs(0,N/2);

    cout<<ans;
    return 0;
}