#include<iostream>
#include<vector>
#include<stack>
using namespace std;
vector <int> v;
stack <pair<int,int> > s;
int arr[500001]={0,};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int N;
	cin>>N;
	s.push(make_pair(0,0));
	for(int i=0,a;i<N;i++){
		cin>>a;
		v.push_back(a);
	}
	for(int i=0;i<N;i++){
		while(!s.empty()){
			if(s.top().first > v[i]){
				arr[i] = s.top().second;
				break;
			}
			s.pop();
		}
		s.push(make_pair(v[i],i+1));
	}
	for(int i=0;i<N;i++) cout<<arr[i]<<" ";
	return 0;
}
