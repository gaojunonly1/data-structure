#include <bits/stdc++.h>
using namespace std;
int fa[100005]; //���׽ڵ� 
int dep[100005]; //��� 
int size[100005]; //������С 
int son[1000005]; //�ض��� 
int rk[100005]; //dfs���е����� 
int top[100005]; //���������Ľڵ� 
int id[100005]; //�ʷֺ���±��
#define pb push_back
vector<int>G[100005];
int n;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i,pp,qq;
	cin>>n;
	for(i=1;i<n;i++) {
		cin>>pp>>qq;
		G[pp].pb(qq);
		G[qq].pb(pp);
	}
	return 0;
}
