#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
struct TreeNode {
	int id;
	TreeNode *ls;
	TreeNode *rs;
};
vector<int>a(20005),b(20005),pos(20005),jyl(20005),wwx(20005);
void build(int la,int ra,int lb,int rb,TreeNode* &rt);
void dfs(TreeNode *rt);
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin>>n;
	int i,j;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++) {
		cin>>b[i];
		pos[b[i]]=i;
	}
	TreeNode *rt;
	build(0,n-1,0,n-1,rt);
	for(i=1;i<=n;i++)
		cin>>jyl[i];
	wwx[rt->id]=jyl[rt->id];
	dfs(rt);
	for(i=1;i<n;i++)
		cout<<wwx[i]<<" ";
	cout<<wwx[n];
    return 0;
}
void build(int la,int ra,int lb,int rb,TreeNode* &rt) {
	if(la>ra||lb>rb) {
		rt=nullptr;
		return;
	}
	rt=(TreeNode*)malloc(sizeof(TreeNode));
	rt->ls=rt->rs=nullptr;
	rt->id=a[la];
	int oo=pos[a[la]];
	build(la+1,la+oo-lb,lb,oo-1,rt->ls);
	build(la+oo-lb+1,ra,oo+1,rb,rt->rs);
}
void dfs(TreeNode *rt) {
	if(nullptr!=rt->ls) {
		wwx[rt->ls->id]=wwx[rt->id]+jyl[rt->ls->id];
		dfs(rt->ls);
	}
	if(nullptr!=rt->rs) {
		wwx[rt->rs->id]=wwx[rt->id]+jyl[rt->rs->id];
		dfs(rt->rs);
	}
}
