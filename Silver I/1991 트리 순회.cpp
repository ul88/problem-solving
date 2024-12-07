#include<iostream>
#include<vector>
#define MAX 26
using namespace std;
struct Tree{
	char left;
	char right;
};

Tree tree[MAX+1]={};

void preorder(char n){
	if(n == '.') return;
	cout<<n;
	preorder(tree[n-'A'].left);
	preorder(tree[n-'A'].right);
}
void inorder(char n){
	if(n == '.') return;
	inorder(tree[n-'A'].left);
	cout<<n;
	inorder(tree[n-'A'].right);
}
void postorder(char n){
	if(n == '.') return;
	postorder(tree[n-'A'].left);
	postorder(tree[n-'A'].right);
	cout<<n;
}
int main()
{
	int N;
	cin>>N;
	for(int i=0;i<N;i++){
		char a,b,c;
		cin>>a>>b>>c;
		tree[a-'A'] = {b,c};
	}
	preorder('A');
	cout<<"\n";
	inorder('A');
	cout<<"\n";
	postorder('A');
	return 0;
}