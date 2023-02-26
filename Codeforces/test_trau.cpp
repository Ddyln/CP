#include <bits/stdc++.h>
#define rep for(int i=1;i<=n;i++)
using namespace std;typedef long long ll;const ll N=2e5+10;ll T,n,c,a[N],b[N],s[N],t[N];pair<ll,ll> d[N];signed main(){
	freopen("test.inp", "r", stdin);
	freopen("test.ans", "w", stdout);
	cin>>T;while(T--){cin>>n>>c;rep{cin>>a[i];t[i]=min(a[i]+i,n+1-i+a[i]);d[i]=make_pair(t[i],i);}sort(d+1,d+n+1);rep{s[i]=s[i-1]+d[i].first;	b[d[i].second]=i;}ll ans=0;rep{ll r=c-a[i]-i;if(r<0)continue;ll q=upper_bound(s+1,s+n+1,r)-s-1;if(b[i]>q)	q++;else {q=upper_bound(s+1,s+n+1,r+t[i])-s-1;}ans=max(ans,q);}cout<<ans<<endl;} return 0;}