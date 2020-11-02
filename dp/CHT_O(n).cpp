//https://www.spoj.com/problems/ACQUIRE/en/

#include<bits/stdc++.h>
using namespace std;

#define Fast            ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define fWrite          freopen ("out.txt","w",stdout);
#define TC              int t;cin >> t;FOR(tc,1,t)
#define LL              long long
#define ULL             unsigned long long
#define ff              first
#define ss              second
#define pb              push_back
#define pii             pair<int,int>
#define all(a)          a.begin(),a.end()
#define MEM(a,x)        memset(a,x,sizeof(a))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)

struct line{
    LL m,c;
    line(){}
    line(LL m,LL c):m(m),c(c){}
};

struct convex_hull_trick{
    vector<line>lines;
    int ptr = 0;
    convex_hull_trick(){}

    bool bad(line a,line b,line c){
        return (c.c-a.c)*(a.m-b.m) <= (b.c-a.c)*(a.m-c.m);
    }
    void add(line L){
        int sz = lines.size();
        while(sz>=2 and bad(lines[sz-2],lines[sz-1],L)){
            lines.pop_back();
            sz--;
        }
        lines.pb(L);
    }
    LL fnc(int idx,LL x){
        return lines[idx].m*x + lines[idx].c;
    }
    LL query(LL x){
        if(lines.empty()) return 0;
        if(ptr>=lines.size()) ptr = lines.size() - 1;
        while(ptr<lines.size()-1 and fnc(ptr,x)>fnc(ptr+1,x)) ptr++;
        return fnc(ptr,x);
    }
};

int main()
{
    /*
    Required condition:
    i. Minimization problem
    ii. slope decreasing order

    Complexity O(n)
    */

    Fast
    int n;
    cin >> n;
    pii arr[n]; //Width, Height
    REP(i,n) cin >> arr[i].ff >> arr[i].ss;
    sort(arr,arr+n); //Width increasing, Height decreasing

    vector<pii>P;
    //Removing the irrelevant rectangles that falls inside another rectangle
    REP(i,n){
        while(!P.empty() and P.back().ss<=arr[i].ss) P.pop_back();
        P.pb(arr[i]);
    }

    convex_hull_trick cht;
    n = P.size();
    LL dp[n];
    /*
    Recurrence: dp[pos] = for(i->pos) min(dp[i-1] + width[i] * height[pos])
                   y    =                   c     +    m     *     x
    */
    REP(i,n){
        cht.add(line(P[i].ss,i?dp[i-1]:0));
        dp[i] = cht.query(P[i].ff);
    }

    cout << dp[n-1];
}
