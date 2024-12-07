#include<iostream>
using namespace std;
typedef long long ll;
ll memo[81]={0,};
ll fibo(int n){ //피보나치 수열 메모이제이션을 사용해서 
	if(memo[n]!=0){		//큰 수의 피보나치 수열을 사용할 때도 시간초과가 안나게 함
		return memo[n];
	}
	else{
		if(n<=2){
			return 1;
		}else{
			return memo[n] = fibo(n-1)+fibo(n-2);
		}
	}
}
int main()
{
	int N;
	ll cnt=0;
	cin>>N;
	cnt=fibo(N+1)*2+fibo(N)*2; // 둘레 구하는 식 
	cout<<cnt;
	return 0;
} 
