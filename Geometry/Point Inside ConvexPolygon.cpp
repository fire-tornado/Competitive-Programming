#include<bits/stdc++.h>
using namespace std;

#define MAX             100005
#define LL              long long
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)

int n;
struct point{
    LL x,y;
    int triarea(const point a,const point b)
    {
        LL d=x*(a.y-b.y)+a.x*(b.y-y)+b.x*(y-a.y);
        if(d>0) return 1;
        else if(d<0) return -1;
        return d;
    }
}P[MAX];

bool bi_search(const point p)
{
    point o=P[0];
    int l=1,h=n-1,m;
    while(h-l>1)
    {
        m=(l+h)>>1;
        int d=o.triarea(P[m],p);
        if(d<0) h=m;
        else l=m;
    }
    if(o.triarea(P[l],p)<0) return false;
    if(P[l].triarea(P[h],p)<0) return false;
    if(P[h].triarea(o,p)<0) return false;
    return true;
}

int main()
{
    int t;
    scanf("%d",&t);
    FOR(tc,1,t)
    {
        scanf("%d",&n);
        REP(i,n) scanf("%lld %lld",&P[i].x,&P[i].y);
        int q;
        scanf("%d",&q);
        printf("Case %d:\n",tc);
        while(q--)
        {
            point p;
            scanf("%lld %lld",&p.x,&p.y);
            if(P[0].triarea(P[1],p)<0 or P[0].triarea(P[n-1],p)>0) printf("n\n");
            else if(bi_search(p)) printf("y\n");
            else printf("n\n");
        }
    }
}

