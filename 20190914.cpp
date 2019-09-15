//백준 1904번: 01타일

//case(3) = 3
//case(4) = 5
//case(5) = 8
//피보나치 수열과 일치
#include <iostream>

int main()
{
    int array[10];
    array[0]=1;
    array[1]=1;
    int N;
    scanf("%d", &N);
    if(N==1)
    {
        printf("1\n");
        return 0;
    }
    for(int i=2; i<=N; i++)
    {
        array[i%10]=(array[(i-1)%10]+array[(i-2)%10])%15746;
    }
    printf("%d\n", array[N%10]);
    return 0;
}