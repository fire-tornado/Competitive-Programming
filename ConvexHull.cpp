#include<bits/stdc++.h>

using namespace std;

#define MAX             100005
#define ll              long long

#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)

struct point
{
    ll x,y;
    bool operator < (const point &p) const
    {
        return x<p.x || (x==p.x && y<p.y);
    }
} P[MAX],C[MAX];

inline ll Cross(point &o,point &a,point &b)
{
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

void ConvexHull(int np,int &nc)
{
    sort(P,P+np);
    REP(i,np)
    {
        while(nc>=2 and Cross(C[nc-2],C[nc-1],P[i])<=0)
            nc--;
        C[nc++]=P[i];
    }
    int t=nc+1;
    ROF(i,np-1,1)
    {
        while(nc>=t and Cross(C[nc-2],C[nc-1],P[i-1])<=0)
            nc--;
        C[nc++]=P[i-1];
    }
    nc--;
    return;
}

int main()
{
    int nc=0,np;
    scanf("%d",&np);
    REP(i,np)
    {
        scanf("%lld %lld",&P[i].x,&P[i].y);
    }
    ConvexHull(np,nc);
    REP(i,nc)
    {
        printf("%lld %lld\n",C[i].x,C[i].y);
    }
    return 0;
}
