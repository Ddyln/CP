#include<iostream>
using namespace std;
long long a,b,c,d,k;
int main(){
    freopen("test.inp", "r", stdin);
	freopen("test.ans", "w", stdout);
cin>>a>>b>>c>>d>>k;
int r=(b+d)%k;
int res=(b+d)-r;
if(res<=0) cout<<-1;
else{
    for(int i=b;i>=a;i--){
       int u= res-i;
       if (u <c || u>d) continue;
            cout<<i<<" "<<u;
        return 0;
    }
    cout << f[n];
    return 0;
}