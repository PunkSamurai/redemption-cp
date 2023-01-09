#include <bits/stdc++.h>

using namespace std;

int n,m;
long long a[100005],mi;
vector<int> ke[100005];
bool check[100005];

void dfs(int u)
{
    for (int v:ke[u])
    if(!check[v]) {mi=min(mi*1ll,a[v]); check[v]=1;dfs(v);}
}

int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        ke[u].push_back(v);
        ke[v].push_back(u);
    }
    long long res=0;
    for (int i=1;i<=n;i++)
    if (!check[i]) {mi=a[i];check[i]=1;dfs(i);res+=mi;}
    cout<<res;
}
 
     	 	