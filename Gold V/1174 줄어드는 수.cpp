#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
typedef long long ll;
int N;
ll increase_num=0;
ll check(ll n){
    vector <ll> v;
    ll ten=1;
    ll prevN=n,nowN=n;
    while(n!=0){
        v.push_back(n%10);
        n/=10; // 오른쪽부터 자리수 뽑아내기
        if(v.size()==1) continue;
        ten*=10; //현재 자리수를 만들어주기 위함
        prevN/=10; // 기존의 n이 줄어드는 것보다 한타이밍 늦게 줄어들어야하기 때문에
        if(v[v.size()-1]>v[v.size()-2]); // 줄어드는 수가 맞을 때
        else{
            increase_num=(prevN+1)*ten-nowN; // 안되는 수가 나오면 바로 가능한 수로 넘어가기 위한 식
            return false;
        }
    }
    return true;
}
ll dfs(ll n,int cnt){
    if(cnt>N) return n-1;
    else{
        if(check(n)){
            return dfs(n+1,cnt+1);
        }else return dfs(n+increase_num,cnt);
    }
}
int main()
{
    cin>>N;
    if(N>1023) cout<<-1;
    else cout<<dfs(0,1);
    return 0;
}