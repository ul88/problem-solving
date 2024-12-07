#include<iostream>
using namespace std;
int f[41]={0,};
int fib(int n) {
    if (n == 1 || n == 2)
    return 1;  //# ÄÚµå1
    else return (fib(n - 1) + fib(n - 2));
}
int fibonacci(int n) {
    if (n==1 || n==2) return 1;
    else if(f[n]!=0) return 1;
	else return	f[n]=fibonacci(n - 1) + fibonacci(n - 2);
}
int main()
{
	int N;
	cin>>N;
	cout<<fib(N)<<" "<<fibonacci(N)-1;
}
