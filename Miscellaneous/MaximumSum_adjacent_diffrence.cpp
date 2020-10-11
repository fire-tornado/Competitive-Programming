/*
https://toph.co/p/generation-gap
Idea: curly_braces

Maximum Sum possible adjacent pair difference.
*/

#include<bits/stdc++.h>
using namespace std;

#define Fast            ios_base::sync_with_stdio(false);cin.tie(nullptr);
#define LL              long long
#define ff              first
#define ss              second
#define pb              push_back
#define pf              push_front
#define pii             pair<LL,LL>
#define all(a)          a.begin(),a.end()
#define MEM(a,x)        memset(a,x,sizeof(a))
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)

int main()
{
    int n;
    cin >> n;
    vector<pii>v;
    REP(i,n){
        int tmp;
        cin >> tmp;
        v.pb({tmp,i+1});
    }
    sort(all(v));
    deque<pii>dq;
    dq.pb(v[n-1]);
    int i=0,j=n-2;
    LL sum=0;
    while(i<=j){
        pii p=v[i];
        pii q=v[j];

        LL a=abs(p.ff-dq.front().ff);
        LL b=abs(p.ff-dq.back().ff);
        LL d1=max(a,b);

        LL c=abs(q.ff-dq.front().ff);
        LL d=abs(q.ff-dq.back().ff);
        LL d2=max(c,d);

        if(d1>d2){
            if(a>b) dq.pf(p);
            else dq.pb(p);
            i++;
            sum+=d1;
        }
        else{
            if(c>d) dq.pf(q);
            else dq.pb(q);
            j--;
            sum+=d2;
        }
    }
    cout << sum << '\n';
    for(pii p:dq) cout << p.ss << ' ';
}
