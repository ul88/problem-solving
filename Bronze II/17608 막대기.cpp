#include<iostream>
#include<stack>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    stack <int> s;
	int N,cnt=0,max=0;
	cin>>N;
	for(int i=0,a;i<N;i++){
		cin>>a;
		s.push(a);
	}

	s.push(0);
    while(!s.empty()){
        int now = s.top();
        s.pop();
        if(max < now){
            cnt++;
            max = now;
        }
    }
	cout<<cnt;
	return 0;
}