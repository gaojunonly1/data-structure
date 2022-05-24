#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
map<int,int>pos;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	map<int,int>jyl;
	int n;
	cin>>n;
	int i;
	for(i=0;i<n;i++) {
		int oo;
		cin>>oo;
		jyl[oo]++;
		if(0==pos.count(oo))
			pos[oo]=i;
	}
	struct node {
		int num,tot;
		bool operator<(node &tmp) {
			return pos[num]<pos[tmp.num];
		}
	};
	vector<node>wwx;
	for(auto oo:jyl)
		wwx.pb((node){oo.fi,oo.se});
	sort(wwx.begin(),wwx.end());
	for(auto oo:wwx)
		cout<<oo.num<<" "<<oo.tot<<endl;
    return 0;
}
