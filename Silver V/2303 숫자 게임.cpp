#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int f(vector<int> v){
    int ans = 0;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                if(i==j || j==k || i==k) continue;
                ans = max(ans,(v[i]+v[j]+v[k])%10);
            }
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    int N;
    cin>>N;
    priority_queue <pair<int,int> > pq;
    vector <vector<int> > v(N+1,vector<int>(5,0));
    for(int i=0;i<N;i++){
        for(int j=0;j<5;j++){
            cin>>v[i][j];
        }
    }

    for(int i=0;i<N;i++){
        pq.push({f(v[i]),i});
    }

    cout<<pq.top().second+1;
    return 0;
}