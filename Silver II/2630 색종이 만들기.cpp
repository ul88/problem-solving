#include<iostream>
#include<vector>
using namespace std;
typedef pair<int,int> pii;
pii ans = {0, 0};
void solve(vector <vector<int>> &v, pii x, pii y){
    if(x.first == x.second || y.first == y.second) return;
    int cnt = 0;
    for(int i=y.first;i<y.second;i++){
        for(int j=x.first;j<x.second;j++){
            if(v[i][j] == 1) cnt++;
        }
    }

    if(cnt == (x.second - x.first) * (y.second-y.first)){
        ans.second++;
    }else if(cnt == 0){
        ans.first++;
    }else{
        solve(v, {x.first, (x.second+x.first)/2}, {y.first, (y.second+y.first)/2});
        solve(v, {x.first, (x.second+x.first)/2}, {(y.second+y.first)/2, y.second});
        solve(v, {(x.second+x.first)/2, x.second}, {y.first, (y.second+y.first)/2});
        solve(v, {(x.second+x.first)/2, x.second}, {(y.second+y.first)/2, y.second});
    }

}
int main()
{
    int N;
    cin>>N;
    vector <vector<int>> v(N, vector<int>(N,0));

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>v[i][j];
        }
    }

    solve(v,{0,N},{0,N});

    cout<<ans.first<<"\n"<<ans.second;
    return 0;
}