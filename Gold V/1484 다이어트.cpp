#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
using ll = long long;
int main()
{
    vector<ll> v;
    ll G;
    cin>>G;
    
    ll i = 1, j = 1;

    while(1){
        if(i*i - j*j == G){
            v.push_back(i);
        }

        if(i-j == 1 && i*i - j*j > G) break;
        if(i*i - j*j > G) j++;
        else i++;
    }

    if(v.empty()){
        cout<<-1;
        return 0;
    }
    sort(v.begin(),v.end());
    for(i=0;i<v.size();i++){
        cout<<v[i]<<"\n";
    }
    return 0;
}