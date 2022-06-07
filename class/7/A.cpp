#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T,m,n;
	int i,j;
	cin>>T>>m;
	while(T--) {
		stack<int>stk;
		bool wwx=0;
		while(0==stk.empty())
			stk.pop();
		j=0;
		cin>>n;
		vector<int>jyl(n);
		for(i=0;i<n;i++)
			cin>>jyl[i];
		for(i=0;i<n;i++) {
			stk.push(i+1);
			if((size_t)stk.size()>m) {
				wwx=1;
				break;
			}
			while(0==stk.empty()&&stk.top()==jyl[j]) {
				j++;
				stk.pop();
			}
		}
		while(0==stk.empty()&&stk.top()==jyl[j]) {
			j++;
			stk.pop();
		}
		if(0==wwx&&1==stk.empty())
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
    return 0;
}
