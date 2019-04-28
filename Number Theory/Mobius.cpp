#include<bits/stdc++.h>

using namespace std;

#define MEM(a,x)        memset(a,x,sizeof(a))

const int N=1000001;
int mu[N];

void mobius()
{
    MEM(mu,-1);
    mu[1]=1;
    for(int i = 2; i<N; i++)
    {
        if(mu[i])
        {
            for(int j = i+i; j<N; j += i)
                mu[j] -= mu[i];
        }
    }
    return;
}
