#include <bits/stdc++.h>
using namespace std;
int n,m;
#define pb push_back
vector<int>G[50005];
bool vis[50005];
int wwx;
void dfs(int u);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,u,v;
	cin>>n>>m;
	for(i=1;i<=m;i++) {
		cin>>u>>v;
		G[u].pb(v);
		G[v].pb(u);
	}
	for(i=1;i<=n;i++) {
		if(vis[i])
			continue;
		dfs(i);
		wwx++;
	}
	cout<<wwx<<endl;
	return 0;
}
void dfs(int u) {
	vis[u]=1;
	for(auto v:G[u])
		if(!vis[v])
			dfs(v);
}
