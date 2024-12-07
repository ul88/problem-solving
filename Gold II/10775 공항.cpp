#include<iostream>
#define MAX 100001
using namespace std;
int G,P,gi[MAX]={0,},parent[MAX]={0,};
int find(int n){
	if(n==parent[n]) return n;
	return parent[n]=find(parent[n]);
}
void Union(int x,int y){
	if(x==y) return;
	if(x < y) parent[y] = x;
	else parent[x] = y;
}
int main()
{
	int cnt=0;
	cin>>G>>P;
	for(int i=0;i<P;i++){
		cin>>gi[i];
	}
	for(int i=1;i<=G;i++) parent[i]=i;
	for(int i=0;i<P;i++){
		if(find(gi[i])!=0){
			Union(find(gi[i]),find(gi[i])-1);
			cnt++;
		}else break;
	}
	cout<<cnt;
	return 0;
}
