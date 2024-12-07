#include<iostream>
#include<vector>
using namespace std;
int main()
{
    vector<int> v;
    int N,K;
    cin>>N>>K;
    if(N <= K){
        cout<<0;
        return 0;
    }

    int temp = 1;
    int ans=0;
    while(N){
        if(N%2){
            v.push_back(temp);
            N--;
        }
        temp*=2;
        N/=2;    
    }
    
    if(N+v.size() <= K){
        cout<<0;
        return 0;
    }

    for(int i=0;i<v.size()-1;i++){
        if(v[i] != v[i+1]){
            while(v[i] != v[i+1]){
                ans += v[i];
                v[i]*=2;
            }
        }
        v[i+1]*=2;
        if(v.size()-(i+1) <= K) break;
    }

    cout<<ans;
    return 0;
}