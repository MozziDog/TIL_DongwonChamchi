//백준 2156번: 포도주 시식

//틀림 왜지?

#include <iostream>

int wine[10001];
int tmp[10001];

int max(int a, int b) { return a>b? a: b; }

int main()
{
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d", &wine[i]);
    }
    tmp[1] = wine[1];
    tmp[2] = wine[1] + wine[2];
    tmp[3] = max(wine[1] + wine[3], wine[2] + wine[3]);
    for(int i=4; i<=n; i++)
    {
        tmp[i] = max(tmp[i-2]+wine[i], tmp[i-3]+wine[i-1]+ wine[i]);
        tmp[i] = max(tmp[i], tmp[i-1]); //이거 중요
    }
    printf("%d\n",tmp[n]);
    return 0;
}