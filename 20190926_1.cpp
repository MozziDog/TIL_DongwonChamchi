//백준 10844번: 쉬운 계단 수
//개쉽네

#include <iostream>

int main()
{
    long tmp[10][10];   //끝자리가 n으로 끝나는 계단수를 저장하는 배열 * 회전 큐 10개 분량
    for(int i = 0; i<10; i++)
    {
        tmp[1][i] = 1;
    }
    tmp[1][0] = 0;

    int N;
    scanf("%d", &N);
    for(int i = 2; i<=N; i++)
    {
        for(int j=0; j<10; j++)
        {
            if(j==0)
            {
                tmp[i%10][j] = tmp[(i-1)%10][j+1];
            }
            else if(j==9)
            {
                tmp[i%10][j] = tmp[(i-1)%10][j-1];
            }
            else
            {
                tmp[i%10][j] = (tmp[(i-1)%10][j-1] + tmp[(i-1)%10][j+1]) % 1000000000;
            }
        }
    }
    long answer = 0;
    for(int i=0; i<10; i++)
    {
        answer += tmp[N%10][i];
    }
    printf("%ld\n", answer%1000000000);
    return 0;
}