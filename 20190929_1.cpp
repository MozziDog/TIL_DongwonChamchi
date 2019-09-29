//백준 2630번: 색종이 만들기

#include <iostream>

using namespace std;

int square[128][128];
int blue, white;

void solve(int x, int y, int n)
{
    if(n == 1)
    {
        if(square[x][y] == 1)
            blue++;
        else
            white ++;
        return;
    }
    int color;
    color = square[x][y];
    for (int i = x; i < (x + n); i++)
    {
        for (int j = y; j < (y + n); j++)
        {
            if(square[i][j] != color)
            {
                solve(x, y, n/2);
                solve(x, y+n/2, n/2);
                solve(x+n/2, y, n/2);
                solve(x+n/2, y+n/2, n/2);
                return;
            }
        }
    }
    if(color == 1)
        blue++;
    else
        white ++;
    return;
}

int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> square[i][j];
        }
    }
    solve(0,0,N);
    cout<<white<<endl<<blue<<endl;
    return 0;
}