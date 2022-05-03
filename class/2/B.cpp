#include <bits/stdc++.h>
using namespace std;
int n,deg[100005];
int tot=0;
char a[100005],aa[100005];
int jyl;
#define pb push_back
vector<int>wwx[100005];
void play(int wy,int rt);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>a[i];
	for(i=1;i<=n;i++)
		cin>>deg[i];
	jyl=1;
	while(jyl<=n) {
		wwx[0].pb(jyl);
		play(1,jyl);
		jyl++;
	}
	for(i=0;;i++) {
		if(!wwx[i].size())
			break;
		for(auto oo:wwx[i])
			aa[++tot]=a[oo];
	}
	for(i=1;i<tot;i++)
		cout<<aa[i]<<" ";
	cout<<aa[tot]<<endl;
	return 0;
}
void play(int wy,int rt) {
	int i;
	for(i=1;i<=deg[rt];i++) {
		wwx[wy].pb(++jyl);
		play(wy+1,jyl);
	}
}
