#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vt vector
#define ar array
#define pb push_back
#define all(v) v.begin(),v.end()

vt<vt<bool> > v(401,vt<bool>(401));
int r,c;
string res;

/*pair <string, bool> solve2(pair<int,int> curr, int count)
{
    string ans = "";
    bool check = false;
    int x = curr.first, y= curr.second;
    if(x==0 && y==0 && count==0)
        return {"",true};
    if(v[x][y])
        return{"",false};
    v[x][y]=true;
    count = count-1;
    vt<pair<string,pair<int,int> > > points;
    if(x+1<r && x+1>=0 && y<c && y>=0)
        points.pb({"ESWS",{x+1,y}});
    if(x<r && x>=0 && y+1<c && y+1>=0)
        points.pb({"SENE",{x,y+1}});
    if(x-1<r && x-1>=0 && y<c && y>=0)
        points.pb({"SENN",{x-1,y}});
    if(x<r && x>=0 && y-1<c && y-1>=0)
        points.pb({"ESWW",{x,y-1}});

    for(auto p : points)
    {
        pair<string, bool> temp = solve2(p.second,count);
        check|=temp.second;
        if(check)
        {
            ans+=(p.first+temp.first);
            break;
        }
    }
    v[x][y]=false;
    count++;
    return {ans,check};
}*/

void dfs(int x, int y, string s, int count)
{
    if(x<0 || y<0 || x>=r || y>=c)
        return;
    if(x==0 && y==0 && count==0)
    {
        res = s;
        return;
    }
    if(v[x][y])
        return;
    v[x][y]=1;
    dfs(x+1,y,s+'S', count-1);
    dfs(x,y+1,s+'E', count-1);
    dfs(x-1,y,s+'N', count-1);
    dfs(x,y-1,s+'W', count-1);
    v[x][y]=0;
    return;
}

string solve()
{
    cin>>r>>c;
    res = "";
    int count = 0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            char c;
            cin>>c;
            bool x = (c=='*')?0:1;
            v[2*i][j] = v[2*i+1][j] = v[2*i][j+1] = v[2*i+1][j+1] = x;
            if(c=='*')
                count+=4;
        }
    }
    r*=2;
    c*=2;
    dfs(0,0,"",count);
    return res!=""?res:"IMPOSSIBLE";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    for(int z = 1;z<=t;z++)
    {
        string res = solve();
        cout<<"Case #"<<z<<": "<<res<<endl;
    }
    return 0;
}

