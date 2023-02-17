#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=32e4,M=998244353;
 
int a[N],n,k,l[2];
ll p[N];
 
ll cal(int l,int r,int n){
    if(l==0 && r==0)return n<1?1:p[n-1]*k%M;
    if(l==0 || r==0)return p[n];
    if(n<1)return (l!=r);
    if(n==1)return k-1-(l!=r);
    return (p[n-1]*(k-2)+cal(l,r,n-2)+M*2)%M;
}
int main(){
    ios::sync_with_stdio(0);
    freopen("test.inp", "r", stdin);
    freopen("test.ans", "w", stdout);
    cin>>n>>k;
    p[0]=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        p[i]=p[i-1]*(k-1)%M;
    }
    ll ans=1;
    for(int i=1;i<=n+2;i++)if(a[i]>=0){
        ans=ans*cal(a[l[i&1]],a[i],(i-l[i&1]-1)/2)%M;
        l[i&1]=i;
    }
    cout<<ans;
    return 0;
}
     