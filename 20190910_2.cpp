//백준 1850번: 최대공약수

#include <iostream>

using namespace std;

long solve(long a, long b)
{
    if(a%b == 0)
        return b;
    
    return solve(b, a%b);
}
clock_t start;

int main()
{
    long A, B;
    scanf("%ld", &A);
    scanf("%ld", &B);
    for(int i =0 ; i< solve(A, B); i++)
    {
        printf("1");
    }
    printf("\n");
}
