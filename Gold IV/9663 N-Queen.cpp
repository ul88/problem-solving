#include<iostream>
using namespace std;
int N,visit[15][15]={0,},ans=0;
bool search(int n,int m){
	for(int k=0;k<N;k++){
		if(visit[k][m]) return false;
		if(n+k<N && m+k<N && visit[n+k][m+k]) return false;
		if(n-k>=0 && m+k<N && visit[n-k][m+k]) return false; 
		if(n+k<N && m-k>=0 && visit[n+k][m-k]) return false;
		if(n-k>=0 && m-k>=0 && visit[n-k][m-k]) return false;
	}
	return true;
}
void backTracking(int cnt){
	if(cnt==N){
		ans++;
		return;
	}else{
		for(int i=0;i<N;i++){
			if(!visit[cnt][i]){
				if(!search(cnt,i)) continue;
				visit[cnt][i]=1;
				backTracking(cnt+1);
				visit[cnt][i]=0;	
			}
		}
	}
}
int main()
{
	cin>>N;
	backTracking(0);
	cout<<ans;
	return 0;
}
