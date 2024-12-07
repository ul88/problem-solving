#include<iostream> 
#include<vector>
using namespace std;
vector <int> v;
vector <int> party[51];

//Union-Find
int parent[51]={0,};
int Find(int n){
	if(n==parent[n]){
		return n;
	}else{
		return parent[n]=Find(parent[n]);
	}
}
void Union(int x,int y){
	x=Find(x);
	y=Find(y);
	if(x!=y){
		if(x<y) parent[y]=x;
		else parent[x]=y;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	int N,M,P,ans=0;
	cin>>N>>M>>P;
	for(int i=1;i<=N;i++) parent[i]=i;
	for(int i=0,a;i<P;i++){
		cin>>a;
		v.push_back(a);
	}
	for(int i=0,a;i<M;i++){
		cin>>a;
		for(int j=0,b,tmp;j<a;j++){
			cin>>b;
			if(j==0) tmp=b;
			else Union(tmp,b);
			party[i].push_back(b);
		}
	}
	
	for(int i=0;i<M;i++){
		bool flag = false;
		for(int j=0;j<party[i].size();j++){
			for(int k=0;k<P;k++){
				if(Find(party[i][j]) == Find(v[k])){
					flag=true;
					break;
				}
			}
		}
		if(flag==false){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
