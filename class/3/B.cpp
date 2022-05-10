#include <bits/stdc++.h>
using namespace std;
int n,m;
int wwx;
vector<int>jyl;
void dfs(int low,int nn,int mm);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	dfs(1,n,m);
	cout<<wwx<<endl;
	return 0;
}
void dfs(int low,int nn,int mm) {
	int i;
	if(mm==1) {
		if(nn<low)
			return;
		for(auto oo:jyl)
			cout<<oo<<" ";
		cout<<nn<<endl;
		wwx++;
		return;
	}
	for(i=low;i*mm<=nn;i++) {
		jyl.push_back(i);
		dfs(i,nn-i,mm-1);
		jyl.pop_back();
	}
}
