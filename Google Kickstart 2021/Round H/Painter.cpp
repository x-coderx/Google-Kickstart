#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector
#define ar array
#define pb push_back
#define all(v) v.begin(),v.end()

/*
U = Uncolored
R = Red
Y = Yellow
B = Blue
O = Orange
P = Purple
G = Green
A = Gray

*/

bool check(unordered_map<char, string> mp, char x, char y)
{

}

long long solve()
{
    int n;
    cin>>n;
    string a;
    cin>>a;
    long long min_red =0ll,min_blue=0ll,min_yellow=0ll;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='R'||a[i]=='O'|| a[i]=='P'||a[i]=='A')
        {
            min_red++;
            while((a[i+1]=='R'||a[i+1]=='O'||a[i+1]=='P'||a[i+1]=='A') && i+1<a.size())
                i++;
        }
    }
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='Y'||a[i]=='O'||a[i]=='G'||a[i]=='A')
        {
            min_yellow++;
            while((a[i+1]=='Y'||a[i+1]=='O'||a[i+1]=='G'||a[i+1]=='A') && i+1<a.size())
                i++;
        }
    }
    for(int i=0;i<a.size();i++)
    {
        if(a[i]=='B'||a[i]=='G'||a[i]=='P'||a[i]=='A')
        {
            min_blue++;
            while((a[i+1]=='B'||a[i+1]=='G'||a[i+1]=='P'||a[i+1]=='A') && i+1<a.size())
                i++;
        }
    }
    return min_red+min_blue+min_yellow;
}

int main()
{
    int t;
    cin>>t;
    for(int z = 1;z<=t;z++)
    {
        long long res = solve();
        cout<<"Case #"<<z<<": "<<res<<endl;
    }
    return 0;
}
