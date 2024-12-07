#include<iostream>
#include<string>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--){
		int B=0,W=0,cnt=0,N;
		string S[2];
		cin>>N;
		cin>>S[0]>>S[1];
	
		for(int j=0;j<N;j++){
			if(S[0][j]==S[1][j]) continue;
			else{
				if(S[0][j]=='B') B++;
				else W++;
			}
		}
		cout<<max(B,W)<<"\n";
	}
	return 0;
}
