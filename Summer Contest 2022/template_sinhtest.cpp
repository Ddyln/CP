#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e5;
const int N=1e6+9;
int rlr(int l,int r)
{
    int tmp=(rand())%mod;
    int len=r-l+1;
    (tmp%=len)+=1+l;
    return tmp;
}
int rll()
{
    int tmp=(1LL*rand()*rand()*rand())%mod;
    return tmp;
}
typedef pair <int,int> ii;
ii id[N];
int l[N],p[N],a[N];
int sigmoi=80;
void sinhcay()
{
  ofstream cout("test.inp");
  int n=(rand()*rand())%(int)10+1;
	// int k=rand()%10+1;
	cout<<n<<endl;
	// int maxxxx=0;
  // for (int i=1;i<=n;i++)
  //   cout<<rand()%5+1<<" ";
  // cout<<endl;
	for (int i=2;i<=n;i++)
	{
		int tmp=rand()%(i-1)+1;
	  cout<<min(i,tmp)<<" "<<max(i,tmp)<<" "<<endl;//<<" "<<rand()%10+1<<endl;//<<" "<<rand()%(n)+1<<endl;
	}
  // int q=rand()%100+1;
  // cout<<q<<endl;
  // for (int i=1;i<=q;i++)
  //   cout<<rand()%10+1<<endl;
	cout.close();
}
typedef pair <int,int> ii;
typedef pair <int,ii> iii;
void sinhtest()
{
   ofstream cout("sc3.inp");
   cout<<1<<endl;
   int n,q;
   do
   {
    n=rand()%10+1;
    q=rand()%5+1;
   } while (q>n*n-n);
   cout<<n<<" "<<q<<endl;
   for (int i=1;i<=n;i++)
     a[i]=rand()%10+1;
    set <iii> s;
  for (int i=1;i<=n;i++)
    for (int j=1;j<=n;j++)
      if (i!=j) s.insert({rand(),{i,j}});
  for (int i=1;i<=q;i++)
    {
      auto it=s.begin();
      iii tmp=*it;
      s.erase(it);
      int code=tmp.first;
      if (code%2==0)
        {
          cout<<"? "<<tmp.second.first<<" "<<tmp.second.second<<endl;
        }
      else 
        {
          cout<<"! "<<tmp.second.first<<" "<<tmp.second.second<<" ";
          cout<<a[tmp.second.first]-a[tmp.second.second]<<endl;
        }
    }
   cout.close();
   ofstream Cout("test.out");
   Cout<<n<<endl;
   for (int i=1;i<=n;i++)
     Cout<<a[i]<<" ";
     Cout.close();
}
signed main()
{
    srand(time(NULL));
    ios::sync_with_stdio(false);
    cin.tie(0);
    int test=1000;
    for (int TEST=1;TEST<=test;TEST++)
      {
        cerr<<"Test:"<<TEST<<endl;
      //sinhcay(); 
       sinhtest(); 
       system("sc3.exe");
       system("test.exe");
       // cout<<"Correct"<<endl;
        if (system("fc sc3.out check2.out")!=0)
          {
              cout<<"WA";
            return 0;
          }
        cout<<"Correct"<<endl;
        // return 0;
      }
    return 0;
}