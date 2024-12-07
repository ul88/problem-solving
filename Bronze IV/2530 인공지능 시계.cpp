#include<stdio.h>
int main()
{
    int A, B, C, D;
    scanf("%d %d %d %d",&A,&B,&C,&D);

    printf("%d %d %d",((((C+D) / 60 + B) / 60)+A)%24,((C+D) / 60 + B) % 60,(C+D) % 60); 
    return 0;
}