#include<stdio.h>
int main()
{
    int N;
    scanf("%d",&N);
    printf("%c%d\n",(N+8)%12+'A',(N+6)%10);
    return 0;
}