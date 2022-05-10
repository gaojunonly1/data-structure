#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef pair<int,int> pii;
#define pb push_back
vector<pii>G[10005];
int n,m;
int cost[10005];
int wwx;
priority_queue<pii>que;
bool flg[10005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,u,v,w;
	cin>>n>>m;
	for(i=1;i<=n;i++) {
		cin>>w;
		G[0].pb(pii(i,w));
		G[i].pb(pii(0,w));
	}
	for(i=1;i<=m;i++) {
		cin>>u>>v>>w;
		G[u].pb(pii(v,w));
		G[v].pb(pii(u,w));
	}
	memset(cost,63,sizeof cost);
	que.push(pii(cost[0]=0,0));
	while(!que.empty()) {
		u=que.top().se;
//		cout<<que.top().se<<" "<<que.top().fi<<" ";
		que.pop();
//		if(!que.empty())
//			cout<<"@@  "<<que.top().se<<" "<<que.top().fi<<endl;
		if(flg[u])
			continue;
		flg[u]=1;
		wwx+=cost[u];
		for(auto tmp:G[u]) {
			v=tmp.fi;
			w=tmp.se;
			if(cost[v]>w&&!flg[v]) {
				cost[v]=w;
				que.push(pii(-w,v));
			}
		}
	}
	cout<<wwx<<endl;
	return 0;
}
