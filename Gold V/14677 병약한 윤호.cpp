#include<iostream>
#include<queue>
#include<set>
#define MAX 500
using namespace std;
struct st{
    int left;
    int right;
    int index;
    int cost;
};
int bfs(string& str){
    set <pair<int,int>> s;
    char drug[3] = {'B', 'L', 'D'};
    queue <st> q;
    int ans = 0;
    q.push({0,(int)str.length()-1, 0, 0});
    while(!q.empty()){
        st now = q.front();
        q.pop();
        if(s.find({now.left,now.right}) != s.end()) continue;
        s.insert({now.left,now.right});
        ans = max(ans,now.cost);
        if(now.left > now.right) continue;
        if(str[now.left] == drug[now.index]){
            q.push({now.left+1,now.right,(now.index+1)%3, now.cost+1});
        }
        if(str[now.right] == drug[now.index]){
            q.push({now.left,now.right-1,(now.index+1)%3, now.cost+1});
        }
    }
    
    return ans;
}

int main()
{
    string str;
    int N;
    cin>>N;
    cin>>str;

    cout<<bfs(str);

    return 0;
}