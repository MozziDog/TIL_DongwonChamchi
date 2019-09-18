//백준 9461번: 파도반 수열

//int의 범위 벗어나지는 않는지 체크 잘 할것...

#include <iostream>

int main()
{
    int T; //test case
    int N; // 1<N<100
    long tmp[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9};
    for (int i = 11; i <= 100; i++)
    {
        tmp[i] = tmp[i - 1] + tmp[i - 5];
    }
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &N);
        if (N <= 10)
        {
            printf("%ld\n", tmp[N]);
            continue;
        }
        else
        {
            printf("%ld\n", tmp[N]);
        }
    }
    return 0;
}