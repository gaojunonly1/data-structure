#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int x,y;
	cin>>x>>y;
	int i;
	if(x>y) {
		cout<<x-y<<endl;
		for(i=0;i<x-y-1;i++)
			cout<<x-i-1<<" ";
		cout<<y;
		return 0;
	}
	if(x==y) {
		cout<<0<<endl;
		return 0;
	}
	map<int,int>fa;
	queue<int>que;
	que.push(x);
	while(!que.empty()&&0==fa.count(y)) {
		int u=que.front();
		if(0==fa.count(u+1)) {
			que.push(u+1);
			fa[u+1]=u;
		}
		if(u*2<=200000&&0==fa.count(u*2)) {
			que.push(u*2);
			fa[u*2]=u;
		}
		if(u-1>0&&0==fa.count(u-1)) {
			que.push(u-1);
			fa[u-1]=u;
		}
		que.pop();
	}
	fa[x]=x;
	vector<int>wwx;
	while(y!=fa[y]) {
		wwx.pb(y);
		y=fa[y];
	}
	cout<<wwx.size()<<endl;
	reverse(wwx.begin(),wwx.end());
	for(i=0;i<(size_t)wwx.size()-1;i++)
		cout<<wwx[i]<<" ";
	if(wwx.size())
		cout<<wwx[(size_t)wwx.size()-1];
    return 0;
}
