#include<iostream>
#define MAX 999
using namespace std;
int arr[MAX+1][MAX+1]={0,};
int main()
{
    int dy[4] = {1, 0, -1, 0};
    int dx[4] = {0, 1, 0, -1};
    int N,M;
    cin>>N>>M;
    
    int cnt = N*N;
    int n=0, m=0;
    int flag = 0;
    while(cnt > 0){
        arr[n][m] = cnt--;
        n += dy[flag];
        m += dx[flag];
        if(n >= 0 && n < N && m >= 0 && m < N && arr[n][m] == 0) continue;
        n -= dy[flag];
        m -= dx[flag];
        flag = (flag+1)%4;
        n += dy[flag];
        m += dx[flag];
    }

    pair<int,int> ans;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(arr[i][j] == M) ans = {i,j};
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }
    cout<<ans.first+1<<" "<<ans.second+1;
    return 0;
}