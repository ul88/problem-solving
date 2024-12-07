#include<iostream>
#include<queue>
#include<set>
#define MAX 100000
using namespace std;
typedef pair<int,pair<int,int> > pp;
set <pair<int,int> > visit;
int bfs(int a,int b,int c,int d){
	queue <pp> q;
	q.push({0,{0,0}});
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second.first;
		int cnt = q.front().second.second;
		q.pop();
		if(x==c && y==d) return cnt;
		if(visit.count({x,y})) continue;
		visit.insert({x,y});
		q.push({0,{y,cnt+1}});
		q.push({x,{0,cnt+1}});
		q.push({a,{y,cnt+1}});
		q.push({x,{b,cnt+1}});
		q.push({x<=b-y ? 0 : x-(b-y),{x<=b-y ? x+y : b,cnt+1}});
		q.push({y<=a-x ? x+y : a,{y<=a-x ? 0 : y-(a-x),cnt+1}});
	}
	return -1;
}
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	cout<<bfs(a,b,c,d);
	return 0;
}