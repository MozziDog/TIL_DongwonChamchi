//백준 2579번: 계단 오르기

//조건 1. 한 번에 한계단 or 두계단
//조건 2. 계단 3개 연속으로 불가능.
//조건 3. 마지막 도착 계단은 반드시 밟아야 함.

/*
//오답
#include <iostream>

int main()
{
    int N;
    int *score;
    int total;
    int continuous = 0;
    scanf("%d", &N);
    score = new int[N+1];
    for(int i=1; i<=N; i++)
    {
        scanf("%d", &score[i]);
    }
    for(int i=N; i>0; i--)
    {
        if(i==N)
        {
            total += score[i];
            continuous = 2;
        }
        else if(i==1)
        {
            total += score[i];
            break;
        }
        else if(i==2)
        {
            if(continuous == 1)
            {
                total += score[i];
                total += score[i-1];
            }
            if(continuous == 2)
            {
                if(score[i]>=score[i-1])
                {
                    total += score[i];
                }
                else
                {
                    total += score[i-1];
                }
            }
                break;
        }
        else
        {
            if(score[i]>=score[i-1])
            {
                total +=score[i];
                continuous = 1;
            }
            else
            {
                total += score[i-1];
                continuous = 2;
            }
                i--;
        }
    }
    printf("%d", total);
    return 0;
}
*/

//인터넷에서 가져온 소스
#include <iostream>
using namespace std;
 
int n,stair[301];
int dp[301];
 
int Max(int a, int b) {
    return a > b ? a : b;
}
 
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &stair[i]);
    }
 
    dp[0] = stair[0];
    dp[1] = Max(stair[0]+stair[1],stair[1]);
    dp[2] = Max(stair[0]+stair[2],stair[1]+stair[2]);
 
    for (int i = 3; i < n; i++) {
        dp[i] = Max(dp[i-2]+stair[i], stair[i-1]+stair[i]+dp[i-3]);
    }
 
    printf("%d\n", dp[n-1]);
 
    return 0;
}
