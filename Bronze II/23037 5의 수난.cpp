#include<iostream>
#include<string>
using namespace std;
int main()
{
	int hap=0;
	string str;
	cin>>str;
	for(int i=0;i<str.size();i++){
		int tmp=str[i]-48;
		hap+=(tmp*tmp*tmp*tmp*tmp);
	}
	cout<<hap;
	return 0;
}
