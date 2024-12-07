#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int N;
    cin>>N;
    vector <int> v(N+1,0);
    for(int i=0;i<N;i++){
        cin>>v[i];
    }

    sort(v.begin(),v.end());
    
    int ans=0;
    for(int i=0;i<v.size();i++){
        for(int j=0;j<=i;j++){
            ans+=v[j];
        }
    }

    cout<<ans;
    return 0;
}