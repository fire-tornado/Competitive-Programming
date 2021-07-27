//https://lightoj.com/problem/similar-trees

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

const int N = 10005;
const ULL hs = 3797;
vector<int>G[2][N];
ULL Key[N];
int height[2][N];

void dfs(int type,int s,int pr){
    for(int u:G[type][s]){
        if(u!=pr){
            height[type][u] = height[type][s] + 1;
            dfs(type,u,s);
        }
    }
}

ULL getHash(int type,int s,int pr){
    ULL Hash = 1;
    for(int u:G[type][s]){
        if(u!=pr){
            Hash *= (Key[height[type][s]] + getHash(type,u,s));
        }
    }
    return Hash;
}

int generateTree(int type,string str){
    int currNode = 0, maxNumNode = 1, prevNode = 0, n = 0;
    for(char ch:str){
        if(ch=='1'){
            G[type][currNode].pb(maxNumNode);
            G[type][maxNumNode].pb(currNode);

            prevNode = currNode;
            currNode = maxNumNode;
            maxNumNode++;
            n++;
        }
        else{
            int parent = G[type][currNode][0];
            currNode = parent;
            prevNode = parent;
        }
    }
    return n;
}

int main(){
    Key[0] = 1;
    FOR(i,1,N-1) Key[i] = Key[i-1]*hs;

    int t;
    cin >> t;
    cin.ignore();
    for(int tc=1;tc<=t;tc++){
        string a,b;
        getline(cin,a);
        getline(cin,b);

        cout << "Case " << tc << ": ";
        if(generateTree(0,a)!=generateTree(1,b)) cout << "Different\n";
        else{
            if(getHash(0,0,-1)==getHash(1,0,-1)) cout << "Same\n";
            else cout << "Different\n";
        }

        for(int i = 0;i<N;i++) G[0][i].clear(),G[1][i].clear();
    }
}
