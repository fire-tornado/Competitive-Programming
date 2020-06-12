/*
https://codeforces.com/contest/660/problem/F
https://rezwanarefin01.github.io/posts/convex-hull-trick/
*/

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

vector<LL>M,B;

bool bad(int l1,int l2,int l3){
    return (B[l3]-B[l1])*(M[l1]-M[l2]) < (B[l2]-B[l1])*(M[l1]-M[l3]);
}

void add(LL newm,LL newb){
    M.pb(newm);
    B.pb(newb);
    int sz=M.size();
    while(sz>=3 and bad(sz-1,sz-2,sz-3)) {
        sz--;
        M.erase(M.end()-2);
        B.erase(B.end()-2);
    }
}

LL f(int i,LL x){
    return M[i]*x+B[i];
}

LL query(LL x){
    if(!M.size()) return 0;
    int lo=0,hi=M.size()-1,idx=0;
    while(lo<=hi){
        int del=(hi-lo)/3;
        int mid1=lo+del;
        int mid2=hi-del;
        if(f(mid1,x)>f(mid2,x)){
            hi=mid2-1;
            idx=mid1;
        }
        else{
            lo=mid1+1;
            idx=mid2;
        }
    }
    return f(idx,x);
}

const int N=2e5+5;
LL A[N],P[N],S[N];

int main()
{
    Fast
    int n;
    cin >> n;
    FOR(i,1,n){
        cin >> A[i];
        S[i]=S[i-1]+i*A[i];
        P[i]=P[i-1]+A[i];
    }
    LL mx=0;
    add(0,0);
    FOR(i,1,n){
        mx=max(mx,query(P[i])+S[i]);
        add(-i,i*P[i]-S[i]);
    }
    cout << mx;
}
