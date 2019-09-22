//백준 1463번: 1로 만들기

//DP로 푸는 것이 어려워보이니 우선 재귀형식으로 풀어봄.
/*
#include<iostream>

int min(int a, int b) { return a>b?b:a; }
int solve(int n)
{
    if(n==1)
    {
        return 0;
    }
    else if(n%6 == 0) //n이 2의 배수이면서 3의 배수일 경우
    {
        return 1+min(min(solve(n/2), solve(n/3)), solve(n-1));
    }
    else if(n%3 == 0)
    {
        return 1+min(solve(n/3), solve(n-1));
    }
    else if(n%2 == 0)
    {
        return 1+min(solve(n/2), solve(n-1));
    }
    else
    {
        return 1+solve(n-1);
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    printf("%d\n", solve(N));
    return 0;
}
*/
//이제 이걸 DP로 바꾸자
#include <iostream>

int DP[1000001];

int min(int a, int b) { return a>b? b: a; }

int main()
{
    int N;
    scanf("%d", &N);
    DP[1] = 0;
    for(int i=2; i<=N; i++)
    {
        DP[i] = DP[i-1] +1;
        if(i%2==0)
            DP[i] = min(DP[i/2]+1, DP[i]);
        if(i%3 == 0)
            DP[i] = min(DP[i/3]+1, DP[i]);
    }
    printf("%d\n", DP[N]);
    return 0;
}