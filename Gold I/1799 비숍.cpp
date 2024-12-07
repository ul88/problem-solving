#include<iostream>
#include<vector>
using namespace std;
using pii = pair<int,int>;
vector<vector<int>> board;

bool check(pii now){
    //now를 기준으로 왼쪽 위 대각선
    pii temp = now;
    while(temp.first >= 0 && temp.second >= 0){
        if(board[temp.first--][temp.second--] == 1) return false;
    }

    //now를 기준으로 오른쪽 위 대각선
    temp = now;
    while(temp.first >= 0 && temp.second < board.size()){
        if(board[temp.first--][temp.second++] == 1) return false;
    }

    //now를 기준으로 왼쪽 아래 대각선
    temp = now;
    while(temp.first < board.size() && temp.second >= 0){
        if(board[temp.first++][temp.second--] == 1) return false;
    }

    //now를 기준으로 오른쪽 아래 대각선
    temp = now;
    while(temp.first < board.size() && temp.second < board.size()){
        if(board[temp.first++][temp.second++] == 1) return false;
    }

    return true;
}

int dfs(vector<pii>& v, int n){
    int ret = 0;
    if(n == v.size()) return 0;
    if(check(v[n])){
        board[v[n].first][v[n].second] = 1;
        ret = max(ret, dfs(v, n+1) + 1);
        board[v[n].first][v[n].second] = 0;
    }
    
    ret = max(ret, dfs(v, n+1));
    return ret;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<pii> v1, v2;
    int N;
    cin>>N;
    board.resize(N,vector<int>(N,0));
    v1.reserve(N*N);
    v2.reserve(N*N);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            int a;
            cin>>a;
            if(a == 0) continue;
            if((i+j)%2){
                v1.push_back({i,j});
            }else{
                v2.push_back({i,j});
            }
        }
    }

    cout<<dfs(v1, 0) + dfs(v2, 0);
    return 0;
}