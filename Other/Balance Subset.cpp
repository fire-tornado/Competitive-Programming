/*
https://www.spoj.com/problems/SUBSET/

Find all subset of an array such that
it can be partitioned into two groups having equal sum.
*/
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
#define Make(x,p)       (x | (1<<p))

int n,id;
int milk[25];
unordered_set<int>Mask[60000];
unordered_set<int>flag[60000];
unordered_map<int,int>mp;
unordered_set<int>st;

void rec1(int i,int diff,int mask){
    if(i==n/2){
        if(mp[diff]==0) mp[diff]=++id;
        Mask[mp[diff]].insert(mask);
        return;
    }
    rec1(i+1,diff,mask); //left out
    rec1(i+1,diff+milk[i],Make(mask,i)); //Right side
    rec1(i+1,diff-milk[i],Make(mask,i)); //Left side
    return;
}

void rec2(int i,int diff,int mask){
    if(i==n){
        int k=mp[-diff];
        if(flag[k].find(mask)!=flag[k].end()) return;
        for(int p:Mask[k]){
            int m=mask | p;
            if(m!=0 and st.find(m)==st.end()) st.insert(m);
        }
        flag[k].insert(mask);
        return;
    }
    rec2(i+1,diff,mask); //left out
    rec2(i+1,diff+milk[i],Make(mask,i)); //Right side
    rec2(i+1,diff-milk[i],Make(mask,i)); //Left side
    return;
}

int main()
{
    Fast
    cin >> n;
    REP(i,n) cin >> milk[i];
    rec1(0,0,0);
    rec2(n/2,0,0);
    cout << st.size() << '\n';
}
