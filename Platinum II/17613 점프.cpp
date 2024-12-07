#include<iostream>
#include<vector>
#include<map>
using namespace std;
map <pair<int,int>, int> m;
int searchM(int n){ // 메르센 수( M(n) )의 n 구하기
	for(int i=1;i<31;i++){
		if((1<<i)-1 > n){
			return i;
		}
	}
	return 0;
}

int M(int n){ // 메르센 수 M(n)
	return (1<<n)-1;
}

int J(int n){ // 점프넘버 구하기
	int m = searchM(n)-1;
	if(n==M(m)){
		return m;
	}else{
		return m+J(n-M(m));
	}
}

int solve(int left, int right){
	if(left == right){
		return J(left);
	}

	int m_right = searchM(right);
	int m_left = searchM(left);

	if(m.find({left,right}) != m.end()) return m[{left,right}];

	if(M(m_right-1) <= left ){
		return m[{left,right}] = J(M(m_right-1)) + solve(left-M(m_right-1), right-M(m_right-1));
	}else{
		return m[{left,right}] = max(solve(left,M(m_right-1)-1), solve(M(m_right-1),right));
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>T;
	while(T--){
		int x,y;
		cin>>x>>y;
		cout<<solve(x,y)<<"\n";
	}
	return 0;
}