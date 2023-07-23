#include <iostream>
using namespace std;
#define n 7
int res=0;
bool vis[10][10];
int fx[4]={-1,1,0,0},
	fy[4]={0,0,-1,1};
string s;

int way(char c){
	if (c=='U')
		return 0;
	if (c=='D')
		return 1;
	if (c=='L')
		return 2;
	return 3;
}

bool prevCheck(int x,int y,int num){
	if (x==n && y==1)
		return 0;
	int a,b,dem1=0,dem2=0;
	for (int i=0;i<2;i++){
		a=x+fx[i],b=y+fy[i];
		if (vis[a][b])
			dem1++;
	}
	for (int i=2;i<4;i++){
		a=x+fx[i],b=y+fy[i];
		if (vis[a][b])
			dem2++;
	}
	if (dem1+dem2==2 && min(dem1,dem2)==0)
		return 0;
	return 1;
}
void uwu(int x,int y,int num){
	if (num == n * n) {
		if (x == n && y == 1)
			res++;
		return;
	}
	if (!prevCheck(x, y, num))
		return;
	vis[x][y]=1;
	int a,b;
	if (s[num]=='?')
		for (int i=0;i<4;i++){
			a=x+fx[i],b=y+fy[i];
			if (!vis[a][b])
				uwu(a,b,num+1);
		}
	else{
		a=x+fx[way(s[num])],b=y+fy[way(s[num])];
		if (!vis[a][b])
			uwu(a,b,num+1);
	}
	vis[x][y]=0;
}
int main(){
	int m = 2;
	m |= 1 << 0;
	cout << m;
	return 0;
	cin >> s;
	s=' '+s;
	for (int i=0;i<9;i++)
		vis[0][i]=vis[n+1][i]=vis[i][0]=vis[i][n+1]=1;
	uwu(1,1,1);
	cout << res;
	return 0;
}