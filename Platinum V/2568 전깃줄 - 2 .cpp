#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#define MAX 100000
using namespace std;
typedef pair <int,int> pi;
vector <pi> v;
vector <int> LIS;
stack <int> ans;
int dp[MAX+1]={0,};
int main()
{
    int N;
    cin>>N;
    for(int i=0,a,b;i<N;i++){
        cin>>a>>b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    
    //binary_search를 이용한 LIS 구하기
    LIS.push_back(v[0].second);
    dp[0]=0;
    for(int i=1;i<v.size();i++){
        if(v[i].second > LIS.back()){
            LIS.push_back(v[i].second);
            dp[i] = LIS.size()-1;
        }else{
            int pos = lower_bound(LIS.begin(),LIS.end(),v[i].second)-LIS.begin();
            LIS[pos]=v[i].second;
            dp[i]=pos;
        }
    }

    cout<<N-LIS.size()<<"\n";

    int cnt=LIS.size()-1;
    for(int i=N-1;i>=0;i--){
		if(cnt==dp[i]){
			cnt--;
            ans.push(i);
		}
	}

    int idx=ans.top();
    ans.pop();
    for(int i=0;i<N;i++){
        if(idx==i){
            if(ans.empty()) continue;
            idx=ans.top();
            ans.pop();
        }else{
            cout<<v[i].first<<"\n";
        }
    }

    return 0;
}