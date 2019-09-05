//https://www.codechef.com/problems/LYRC/

#include<bits/stdc++.h>
using namespace std;

struct AC{
    int n,p;
    vector<vector<int> >next,out,G;
    vector<int>link,out_link,arr,ans;
    AC() : n(0),p(0) {node();}
    int node(){
        next.emplace_back(63,0);
        link.emplace_back(0);
        out_link.emplace_back(0);
        out.emplace_back(0);
        return n++;
    }
    int get_char(char ch)
    {
        if(ch>='0' and ch<='9') return ch-'0';
        else if(ch>='A' and ch<='Z') return ch-'A'+10;
        else if(ch>='a' and ch<='z') return ch-'a'+36;
        return 62;
    }
    int add_pattern(const string str)
    {
        int u=0;
        for(char ch:str)
        {
            if(!next[u][get_char(ch)]) next[u][get_char(ch)]=node();
            u=next[u][get_char(ch)];
        }
        out[u].push_back(p);
        return p++;
    }
    void build()
    {
        queue<int>Q;
        Q.push(0);
        while(!Q.empty())
        {
            int u=Q.front();
            Q.pop();
            for(int c=0;c<63;c++)
            {
                int v=next[u][c];
                if(!v) next[u][c]=next[link[u]][c];
                else{
                    link[v] = u ? next[link[u]][c] : 0;
                    out_link[v] = out[link[v]].empty() ? out_link[link[v]] : link[v];
                    Q.push(v);
                }
            }
        }
        arr.resize(n,0);
        ans.resize(p,0);
        G.resize(n,vector<int>());
        for(int i=0;i<n;i++) if(i!=link[i]) G[link[i]].emplace_back(i);
    }
    int advance(int u,char ch)
    {
        while(u and !next[u][get_char(ch)]) u=link[u];
        u=next[u][get_char(ch)];
        return u;
    }
    void match(const string str)
    {
        int u=0;
        for(int i=0;i<str.size();i++)
        {
            u=advance(u,str[i]);
            arr[u]++;
            /*
            for(int v=u;v;v=out_link[v])
            {
                for(int r:out[v])
                {

                }
            }
            */
        }
    }
    void dfs(int s)
    {
        for(int u:G[s])
        {
            dfs(u);
            arr[s]+=arr[u];
        }
        for(int u:out[s])
        {
            ans[u]+=arr[s];
        }
    }
}aho;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    for(int i=0;i<q;i++)
    {
        string pat;
        cin >> pat;
        aho.add_pattern(pat);
    }
    aho.build();
    int n;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        string txt;
        cin >> txt;
        aho.match(txt);
    }
    aho.dfs(0);
    for(int i=0;i<q;i++) cout << aho.ans[i] << '\n';
}

