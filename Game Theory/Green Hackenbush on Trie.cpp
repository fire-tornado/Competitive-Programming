//https://vjudge.net/contest/357000#problem/B

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

int tri[4000005][26];
int subtree[4000005];
int id=1;
string str;

void add(int i,int r){
    if(i==str.size()){
        return;
    }
    int x=str[i]-'a';
    if(!tri[r][x]){
        tri[r][x]=++id;
    }
    else{
        subtree[r]^=subtree[tri[r][x]]+1;
    }
    add(i+1,tri[r][x]);
    subtree[r]^=subtree[tri[r][x]]+1;
    return;
}

int main()
{
    Fast
    int t;
    cin >> t;
    FOR(tc,1,t)
    {
        id=1;
        int n;
        cin >> n;
        FOR(i,1,n){
            cin >> str;
            add(0,1);
        }
        int q;
        cin >> q;
        cout << "Case " << tc << ":\n";
        FOR(i,1,q){
            cin >> str;
            add(0,1);
            if(subtree[1]) cout << 1 << '\n';
            else cout << 2 << '\n';
        }
        memset(tri,0,sizeof(tri));
        memset(subtree,0,sizeof(subtree));
    }
}
