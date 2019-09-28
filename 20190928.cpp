//백준 11053번: 가장 긴 증가하는 부분 수열

#include <iostream>

int A[1001];
int dp[1001];

int main()
{
    int N;
    int answer=0;   //Elqk 이거 하나때문에 틀렸었네
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &A[i]);
    }
    for(int i=1; i<=N; i++)
    {
        int min=0;
        for(int j=1; j<i; j++)
        {
            if(A[j]< A[i])
                if(dp[j]>min)
                    min = dp[j];
        }
        dp[i] = min+1;
        if(dp[i]>answer)
            answer = dp[i];
    }
    printf("%d\n", answer);
    return 0;
}