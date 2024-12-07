#include<iostream>
#include<vector>
using namespace std;
using pii = pair<int,int>;
int main()
{
    vector<pii> v;
    int N;
    
    cin>>N;
    for(int i=0,a,b;i<3;i++){
        cin>>a>>b;
        v.push_back({a,b});
    }

    for(int i=0;i<=v[0].first;i++){
        int ab = i;
        int ac = v[0].first - i;
        int cb = v[1].second - ab;
        int bc = v[2].second - ac;
        int ba = v[1].first - bc;
        int ca = v[0].second - ba;
        
        if(ab>=0 && ac>=0 && ba>=0 && bc>=0 && ca>=0 && cb>=0){
            cout<<1<<"\n";
            cout<<ab<<" "<<ac<<"\n";
            cout<<ba<<" "<<bc<<"\n";
            cout<<ca<<" "<<cb<<"\n";
            return 0;
        }
    }

    cout<<0;
    return 0;
}