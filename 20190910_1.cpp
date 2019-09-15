//백준 1094번 막대기

#include <iostream>

int main()
{
    int X;
    scanf("%d", &X);
    //64=1000000b
    int answer=0;
    for(int i=1; i<=64; i*=2)
    {
        if(X&i)
            answer ++;
    }
    printf("%d\n", answer);
    return 0;
}