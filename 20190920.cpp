//백준 1932번: 정수 삼각형

#include <iostream>
/*
재귀 함수 버전
int **tri;
int n;
int fun(int x, int y)
{
    if(x==n)
    {
        return tri[x][y];
    }
    if(fun(x+1, y)>fun(x+1, y+1))
    {
        return fun(x+1, y)+tri[x][y];
    }
    else
    {
        return fun(x+1, y+1)+tri[x][y];
    }
}
int main()
{
    scanf("%d", &n);
    tri=new int*[n+1];
    for(int i=1; i<=n; i++)
    {
        tri[i] = new int[i];
        for(int j=0; j<i; j++)
        {
            scanf("%d", &tri[i][j]);
        }
    }
    printf("%d", fun(1,0));
    return 0;
}
*/

//반복문(DP) 버전
int main()
{
    int **tri;
    int n;
    scanf("%d", &n);
    tri=new int*[n+1];
    for(int i=1; i<=n; i++)
    {
        tri[i] = new int[i];
        for(int j=0; j<i; j++)
        {
            scanf("%d", &tri[i][j]);
        }
    }
    for(int i=n-1; i>0; i--)
    {
        for(int j=0; j<i; j++)
        {
            if(tri[i+1][j] > tri[i+1][j+1])
                tri[i][j] += tri[i+1][j];
            else
            {
                tri[i][j] += tri[i+1][j+1];
            }
        }
    }
    printf("%d",tri[1][0]);
    return 0;
}