#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
int n;
char s[1000005];
int f[1000005];
void calc_f();
int main() {
	while(true) {
		scanf("%s",s+1);
		if(s[1]=='.')
			break;
		n=strlen(s+1);
		calc_f();
		int oo=n;
		while(0!=f[oo]&&f[oo]*2>=oo)
			oo=f[oo];
		printf("%d\n",oo);
	}
    return 0;
}
void calc_f() {
	f[1]=0;
	int i;
	for(i=2;i<=n;i++) {
		f[i]=f[i-1];
		while(s[f[i]+1]!=s[i]&&f[i])
			f[i]=f[f[i]];
		if(s[f[i]+1]==s[i])
			f[i]++;
	}
	f[0]=-1;
}
