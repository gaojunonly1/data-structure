#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
typedef pair<int,int> pii;
#define pb push_back
vector<pii>G[10005];
int n,m,s;
struct node {
	int dist,tot;
};
queue<int>que;
bool inq[10005];
void bfs(int st);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,u,v,w;
	cin>>n>>m>>s;
	s--;
	for(i=1;i<=m;i++) {
		cin>>u>>v>>w;
		u--;
		v--;
		G[u].pb(pii(v,w));
		G[v].pb(pii(u,w));
	}
	bfs(s);
	return 0;
}
void bfs(int st) {
	int u,v,w;
	vector<node>wwx(n);
	for(u=0;u<n;u++)
		wwx[u].dist=192608170;
	wwx[st].dist=wwx[st].tot=0;
	inq[st]=1;
	que.push(st);
	while(!que.empty()) {
		u=que.front();
		que.pop();
		inq[u]=0;
		for(auto tmp:G[u]) {
			v=tmp.fi;
			w=tmp.se;
			if(wwx[u].dist+w<wwx[v].dist) {
				wwx[v].dist=wwx[u].dist+w;
				wwx[v].tot=wwx[u].tot+1;
				if(!inq[v]) {
					que.push(v);
					inq[v]=1;
				}
			}
			if(wwx[u].dist+w==wwx[v].dist)
				wwx[v].tot=max(wwx[v].tot,wwx[u].tot+1);
		}
	}
	for(u=0;u<n-1;u++)
		cout<<wwx[u].dist<<" ";
	cout<<wwx[n-1].dist<<endl;
	for(u=0;u<n-1;u++)
		cout<<wwx[u].tot<<" ";
	cout<<wwx[n-1].tot<<endl;
}
