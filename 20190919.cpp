//백준 1149번: RGB거리

//런타임 에러...?

#include <iostream>

int min(int a, int b)
{
    return a<b?a:b;
}
int min(int a, int b, int c)
{
    return min(min(a,b),c);
}
int main()
{
    int N;
    int input_R, input_G, input_B;
    scanf("%d", &N);
    int* sum[3];
    for(int i=0; i<3; i++)
    {
        sum[i] = new int[N];
    }
    for(int i=0; i<N; i++)
    {
        scanf("%d %d %d", &input_R, &input_G, &input_B);
        if(i==0)
        {
            sum[i][0] = input_R;
            sum[i][1] = input_G;
            sum[i][2] = input_B;
        }
        else
        {
            sum[i][0] = min(sum[i-1][1], sum[i-1][2]) + input_R;
            sum[i][1] = min(sum[i-1][0], sum[i-1][2]) + input_G;
            sum[i][2] = min(sum[i-1][0], sum[i-1][1]) + input_B;
        }  
    }
    printf("%d", min(sum[N-1][0], sum[N-1][1], sum[N-1][2]));
    return 0;
}