#include<bits/stdc++.h>
using namespace std;

long long solve()
{
    int r,c;
    long long res = 0;
    cin>>r>>c;
    vector<vector<int> > v(r,vector<int>(c));
    vector<vector<bool> > vis(r,vector<bool>(c));
    priority_queue<array<int,2> > pq;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>v[i][j];;
            pq.push({v[i][j],i*c+j});
        }
    }

    while(!pq.empty())
    {
        array<int,2> temp = pq.top();
        pq.pop();
        int x = temp[1]/c, y = temp[1]%c;
        if(vis[x][y])
            continue;
        vis[x][y] = true;
        vector<array<int,2> > a;
        if(x && !vis[x-1][y] && v[x-1][y] < v[x][y])
            a.push_back({x-1,y});
        if(x+1<r && !vis[x+1][y] && v[x+1][y] < v[x][y])
            a.push_back({x+1,y});
        if(y && !vis[x][y-1] && v[x][y-1] < v[x][y])
            a.push_back({x,y-1});
        if(y+1<c && !vis[x][y+1] && v[x][y+1] < v[x][y])
            a.push_back({x,y+1});

        for(auto p : a)
        {
            res+=v[x][y]-1-v[p[0]][p[1]];
            v[p[0]][p[1]] = v[x][y]-1;
            pq.push({v[p[0]][p[1]],p[0]*c+p[1]});
        }
    }
    return res;

}

int main()
{
    int t;
    cin>>t;
    for(int z=1;z<=t;z++)
    {
        long long res = solve();
        cout<<"Case #"<<z<<": "<<res<<endl;
    }
    return 0;
}
