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

int tri[10000005][2];
int len[10000005];
int id=1;

string conv(int n){
    string s;
    while(n){
        if(n%2) s+='1';
        else s+='0';
        n/=2;
    }
    while(s.size()!=30) s+='0';
    reverse(all(s));
    return s;
}

void Delete(int val){
    string str=conv(val);
    int r=1;
    REP(i,str.size())
    {
        int x=str[i]-'0';
        r=tri[r][x];
        len[r]--;
    }
}

void Insert(int val){
    string str=conv(val);
    int r=1;
    REP(i,str.size())
    {
        int x=str[i]-'0';
        if(!tri[r][x])
        {
            tri[r][x]=++id;
        }
        r=tri[r][x];
        len[r]++;
    }
}

int Query(int val){
    string ans;
    string str=conv(val);
    int r=1;
    REP(i,str.size())
    {
        int x=str[i]-'0';
        if(len[tri[r][1-x]]>0){
            r=tri[r][1-x];
            ans+='1';
        }
        else {
            r=tri[r][x];
            ans+='0';
        }
    }
    int num=0;
    REP(i,ans.size()) if(ans[i]=='1') num+=(1<<(29-i));
    return num;
}

vector<int>V[500005];
int value[500005];
int result = INT_MIN;

void dfs(int s,int p){
    result = max(result, Query(value[s]));
    Insert(value[s]);
    for(int u:V[s]){
        if(u==p) continue;
        dfs(u,s);
    }
    Delete(value[s]);
}

int main()
{
    Fast
    int n;
	cin >> n;
	for(int i=1;i<=n;i++){
        cin >> value[i];
	}
	for(int i=1;i<n;i++){
        int u,v;
        cin >> u >> v;
        V[u].push_back(v);
        V[v].push_back(u);
	}
	dfs(1,0);
	cout << result;
    return 0;
}
