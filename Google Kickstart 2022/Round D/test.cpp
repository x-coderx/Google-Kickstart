#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector
#define ar array
#define pb push_back
#define all(v) v.begin(),v.end()



int main()
{
    int m;
    cin>>m;
    for (int s=m; s; s=(s-1)&m)
        if(__builtin_popcount(s)==1)
            cout<<s<<endl;
    return 0;
}

