#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#define MAX 100001
using namespace std;
map <int,int> m;
vector <int> graph[MAX];
int parent[MAX]={0,},arr[MAX]={0,};
string s;
queue <int> q;
stack <int> ans;
int N,K,M,J;
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>N>>K;
	for(int i=0;i<N;i++){
		cin>>s;
		parent[i]=-1;
        arr[i]=0;
        for(int j=K-1;j>=0;j--){
            arr[i]<<=1;
            arr[i]|=(s[j]-'0');
        }
        m[arr[i]]=i;
	}
    for(int i=0;i<N;i++){
        for(int j=0;j<K;j++){
            int tmp = arr[i]^(1<<j);
            if(m.find(tmp) != m.end()){
                graph[i].push_back(m.find(tmp)->second);
            }
        }
    }
	q.push(0);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		for(int i=0;i<graph[now].size();i++){
			int next=graph[now][i];
			if(parent[next]==-1){
				q.push(next);
				parent[next]=now;
			}
		}
	}
    cin>>M;
    while(M--){
        cin>>J;
        J--;
        if(parent[J]==-1){
            cout<<-1<<"\n";
        }else{
            int idx=J;
            while(idx != 0){
                ans.push(idx);
                idx=parent[idx];
            }
            ans.push(0);
            while(!ans.empty()){
                cout<<ans.top()+1<<" ";
                ans.pop();
            }
            cout<<"\n";
        }
    }
	return 0;
}
