#include<iostream>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
int main()
{
    vector <pii> v;
    int N;
    cin>>N;
    v.reserve(N);
    for(int i=0;i<N;i++){
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});   
    }

    for(int i=0;i<N;i++){
        int cnt = 1;
        for(int j=0;j<N;j++){
            if(i==j) continue;
            if(v[i].first < v[j].first && v[i].second < v[j].second){
                cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
    return 0;
}