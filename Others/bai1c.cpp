#include <bits/stdc++.h>
using namespace std;

struct Nhanvien
{
    string MaNv, Name, Ban;
    long long Salary, Bonus, RSalary;
} a[10000];

void Nhap(int n)
{
    for (int i=1; i <= n; i++)
    {
        cin.ignore();
        getline(cin, a[i].MaNv);
        getline(cin, a[i].Name);
        getline(cin, a[i].Ban);
        cin >> a[i].Salary >> a[i].Bonus;
        a[i].RSalary = a[i].Salary + a[i].Bonus;
    }
}

long long Tong_RSalary(int n)
{
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        sum += a[i].RSalary;
    }
    return sum;
}

void XuatNV(Nhanvien x)
{
    cout << "Ma nhan vien: " << x.MaNv << endl;
    cout << "Ten nhan vien: " << x.Name << endl;
    cout << "Phong ban: " << x.Ban << endl;
    cout << "Luong co ban: " << x.Salary << endl;
    cout << "Thuong: " << x.Bonus << endl;
    cout << "Thuc lanh: " << x.RSalary << endl;
    cout << endl;
}

void Out_Lowest_Salary(int n)
{
    cout << "DS nhan vien co luong co ban thap nhat: " << endl;
    long long mins = 99999999;
    for (int i = 1; i <= n; i++)
    {
        if (mins > a[i].Salary) mins = a[i].Salary;
    }
    for (int i = 1; i <= n; i++)
    {
        if (mins == a[i].Salary) XuatNV(a[i]);
    }
}

int Count(int n)
{
    int dem = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].Bonus >= 1200000) dem++;
    }
    return dem;
}

bool cmp(const Nhanvien& a, const Nhanvien& b) {
    int tmp = strcmp(a.Ban, b.Ban);
    if (tmp != 0)
        return (tmp < 0);
    return (strcmp(a.MaNV, b.MaNV) >= 0);
}

int main()
{
    
    ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    freopen("test.INP","r",stdin);
    int n;
    //cout << "Nhap so luong nhan vien: ";
    cin >> n;
    Nhap(n);
    cout << "Tong thuc lanh thang cua tat ca nhan vien: ";
    cout << Tong_RSalary(n) << endl;
    cout << endl;
    Out_Lowest_Salary(n);
    cout << "So nhan vien co thuong >= 1tr2: ";
    cout << Count(n);
    return 0;
}