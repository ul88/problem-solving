#include<iostream>
#include<vector>
#define MAX 1000
#define INF INT32_MAX
using namespace std;
int main()
{
    int N;
    cin>>N;
    vector<vector<int>> v(N,vector<int>(5,0));

    for(int i=0;i<N;i++){ // 학생
        for(int j=0;j<5;j++){ // 학년
            cin>>v[i][j];
        }
    }

    int m=-INF,ans=0;
    
    for(int i=0;i<N;i++){
        int cnt = 0;
        vector<int> visit(N,0);
        for(int j=0;j<5;j++){
            for(int k=0;k<N;k++){
                if(i == k) continue;
                if(v[i][j] != v[k][j]) continue;
                if(visit[k] == 1) continue;
                visit[k] = 1;
                cnt++;                
            }
        }
        if(m < cnt){
            m = cnt;
            ans = i;
        }
    }

    cout<<ans+1;

    return 0;
}