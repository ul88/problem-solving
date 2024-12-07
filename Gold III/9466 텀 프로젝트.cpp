#include<iostream>
#include<vector>
#define MAX 100000
using namespace std;
void dfs(int n,vector <int> &v,int &ans,int *visit,int *done){
    visit[n]=1;
    int next = v[n];
    if(!visit[next]){ // 방문한적 없을 때
        dfs(next,v,ans,visit,done);
    }else if(!done[next]){ // 방문한 적이 있지만, 방문이 끝난 노드가 아니라면
        for(int i=next;i != n;i=v[i]){ //개수 확인
            ans++;
        }ans++; // 자기 자신 세기
    }
    done[n]=1; // 해당 노드는 더이상 방문할 일이 없다.
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int T,N;
    cin>>T;
    while(T--){
        vector <int> v;
        int visit[MAX+1]={0,},done[MAX+1]={0,},ans=0;
        v.push_back(0);
        cin>>N;
        for(int i=0,a;i<N;i++){
            cin>>a;
            v.push_back(a);
        }
        for(int i=1;i<=N;i++){
            if(visit[i]) continue;
            dfs(i,v,ans,visit,done);
        }
        cout<<N-ans<<"\n";
    }
    return 0;
}