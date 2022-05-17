#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
int n,m;
vector<int>G[10005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i;
	cin>>n>>m;
	vector<int>deg(n);
	for(i=1;i<=m;i++) {
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		G[v].pb(u);
		deg[u]++;
	}
	queue<int>que;
	vector<int>rk(n);
	for(i=0;i<n;i++)
		if(0==deg[i]) {
			que.push(i);
			rk[i]=0;
		}
	while(0==que.empty()) {
		int u=que.front();
		for(auto v:G[u]) {
			deg[v]--;
			rk[v]=max(rk[v],rk[u]+1);
			if(0==deg[v])
				que.push(v);
		}
		que.pop();
	}
	for(i=0;i<n;i++)
		if(0!=deg[i]) {
			cout<<-1;
			return 0;
		}
	int wwx=0;
	for(i=0;i<n;i++)
		wwx+=rk[i]+888;
	cout<<wwx;
    return 0;
}
