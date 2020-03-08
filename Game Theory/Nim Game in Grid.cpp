#include<bits/stdc++.h>
using namespace std;

#define Fast            ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define LL              long long
#define ff              first
#define ss              second
#define pb              push_back
#define pii             pair<int,int>
#define all(a)          a.begin(),a.end()
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)

int main()
{
    int t;
    scanf("%d",&t);
    FOR(tc,1,t){
        int r,c;
        scanf("%d %d",&r,&c);
        int nim=0;
        FOR(i,1,r){
            FOR(j,1,c){
                int tmp;
                scanf("%d",&tmp);
                if(((r-i)+(c-j))%2){
                    nim^=tmp;
                }
            }
        }
        if(nim) printf("Case %d: win\n",tc);
        else printf("Case %d: lose\n",tc);
    }
}
