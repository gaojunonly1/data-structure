#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
int n,m;
vector<pii>G[100005];
bool whlw(int w1);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i;
	cin>>n>>m;
	vector<int>ww;
	for(i=1;i<=m;i++) {
		int u,v,w;
		cin>>u>>v>>w;
		G[u].pb(pii(v,w));
		G[v].pb(pii(u,w));
		ww.pb(w);
	}
	if(n==1) {
		puts("0");
		return 0;
	}
	sort(ww.begin(),ww.end());
	ww.erase(unique(ww.begin(),ww.end()),ww.end());
	int ll=0,rr=ww.size()-1;
	int wwx;
	while(ll<=rr) {
		int mid=(ll+rr)>>1;
		if(whlw(ww[mid])) {
			wwx=ww[mid];
			rr=mid-1;
		}
		else
			ll=mid+1;
	}
	cout<<wwx;
    return 0;
}
bool whlw(int w1) {
	vector<bool>vis(n,0);
	vis[1]=1;
	queue<int>que;
	que.push(1);
	while(0==que.empty()) {
		int u=que.front();
		for(auto oo:G[u]) {
			int v=oo.fi,w=oo.se;
			if(w<=w1&&!vis[v]) {
				vis[v]=1;
				que.push(v);
			}
		}
		que.pop();
	}
	return vis[n];
}
