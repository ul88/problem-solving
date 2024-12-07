#include<iostream>
#include<stack>
#include<string>
using namespace std;
stack <int> s;
string S="";
int len=0;
void dfs(int start,int last){
	if(start>=len) return;
	else{	
		char idx=S[start];
		if(idx==')' || idx==']') dfs(start+1,last);
		else{
			
			for(int i=start+1;i<=last;i++){
				if(idx=='('){
					if(S[i]==')'){
						s.push(i);
					}
				}else if(idx=='['){
					if(S[i]==']'){
						s.push(i);
					}
				}
			}
			while(!s.empty()){
				printf("%c %c\n",S[start],S[s.top()]);
				dfs(start+1,s.top()-1);
				s.pop();
			}
		}
	}
}
int main()
{
	cin>>S; 
	while(S[++len]!='\0');
	dfs(0,len);
	return 0;
}
