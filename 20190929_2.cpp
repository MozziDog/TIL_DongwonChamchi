//백준 15649번: N과 M
//DFS
//시간 초과

#include <iostream>

using namespace std;

int N, M;
int *index;
bool *visit;
int tmp = 0;

void solve(int a)
{
    if (a == M)
    {
        for (int i = 1; i <= N; i++)
        {
            if (visit[i] == false)
            {
                visit[i] = true;
                index[a] = i;
                for (int j = 1; j <= M; j++)
                {
                    std::cout << index[j] <<" ";
                }
                std::cout<<std::endl;
                visit[i] = false;
            }
        }
        return;
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            //cout<<endl<<i<<endl;
            if (visit[i] == false)
            {
                //cout<<"yes"<<endl;
                index[a] = i;
                visit[i] = true;
                solve(a+1);
                visit[i] = false;
            }
        }
    }
}

int main()
{
    std::cin >> N;  //1부터 N까지의 자연수 중에
    std::cin >> M;  //M개 뽑기
    index = new int[M + 1];
    visit = new bool[N + 1];
    for(int i=0; i<=N; i++)
    {
        visit[i] = false;
    }
    solve(1);
}