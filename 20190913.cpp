//백준 1003번: 피보나치 함수
//DP를 연습해보자
#include <iostream>

int memo[41] = {1,1};

int fibonacci(int n)
{
    if(n<2)
        return memo[n];
    else if(memo[n]>0)
        return memo[n];
    return memo[n]= fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    int T, N;
    scanf("%d", &T);
    for(int i=0; i<T; i++)
    {
        scanf("%d", &N);
        if(N==0)
        {
            printf("1 0\n");
        }
        else if(N==1)
        {
            printf("0 1\n");
        }
        else
        {
            fibonacci(N);
            printf("%d %d\n", memo[N-2], memo[N-1]);
        }
    }
    return 0;
}