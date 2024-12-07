#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#define MOD 999979
using namespace std;
typedef pair<int,int> p;
vector <int> prime;
vector <p> v[MOD];
bool isPrime(int n){
    if(n<2) return 0;
    for(int i=2;i*i<=n;i++) if(n%2==0) return 0;
    return 1;
}
void getPrime(){
    for(int i=2; i<=1000;i++){
        if(isPrime(i)) prime.push_back(i);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int ans=0;
    string str1,str2;
    cin>>str1>>str2;
    getPrime(); //해시의 키 값은 중복이 나올 확률이 적어야하므로 소수로 알파벳에 대칭해줌
    for(int i=0;i<str2.size();i++){ //str1으로 먼저하면 시간초과 (왜 인지는 모르겠음)
        int x=1,y=1;
        for(int j=i;j<str2.size();j++){
            x=(x*prime[str2[j]-'a'])%MOD; // 해싱
            y=(y*prime[str2[j]-'a'+26])%MOD; //2중 해싱
            int len = j-i+1;
            v[x].push_back({y,len});
        }
    }
    for(int i=0;i<str1.size();i++){
        int x=1,y=1;
        for(int j=i;j<str1.size();j++){
            x=(x*prime[str1[j]-'a'])%MOD;
            y=(y*prime[str1[j]-'a'+26])%MOD;
            int len = j-i+1;
            for(int k=0;k<v[x].size();k++) if(v[x][k] == make_pair(y,len)) ans=max(ans,len); //두 해시값이 모두 일치한다면 길이 비교
        }
    }
    cout<<ans;
    return 0;
}