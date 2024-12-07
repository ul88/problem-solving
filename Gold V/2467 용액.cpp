#include<iostream>
#include<vector>
#include<algorithm>
#define INF 2000000002
using namespace std;
vector <int> v;
int arr[2];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int N,ans=INF; 
	cin>>N;
	for(int i=0,a;i<N;i++){
		cin>>a;
		v.push_back(a);
	}
	int left = 0, right = v.size()-1;
	while(left < right){
		if(ans>abs(v[left] + v[right])){
			ans=abs(v[left]+v[right]);
			arr[0] = v[left];
			arr[1] = v[right];
		}
		if(v[left] + v[right] < 0){
			left++;
		}else{
			right--;
		}
	}
	cout<<arr[0]<<" "<<arr[1];
	return 0;
}
