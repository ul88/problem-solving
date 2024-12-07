#include<stdio.h>
int main()
{
	int A[10],B[10];
	int a=0,b=0;
	for(int i=0;i<10;i++){
		scanf("%d",&A[i]);
	}
	for(int i=0;i<10;i++){
		scanf("%d",&B[i]);
	}
	for(int i=0;i<10;i++){
		if(A[i]>B[i]) a++;
		else if(A[i]<B[i])b++;
	}
	if(a==b) printf("D");
	else if(a>b) printf("A");
	else printf("B");
	return 0;
}