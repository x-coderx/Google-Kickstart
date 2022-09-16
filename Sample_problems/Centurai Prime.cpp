#include<bits/stdc++.h>
using namespace std;
int main()
{
    int num_cases;
    cin>>num_cases;

    string kingdom;

    for(int i=0;i<num_cases;i++)
    {
        cin>>kingdom;
        char last_char = kingdom[kingdom.size()-1];

        if(last_char=='y' || last_char =='Y')
        {
            cout<<"Case #"<<i+1<<": "<<kingdom<<" is ruled by nobody"<<endl;
            continue;
        }

        int check = (last_char=='a'|| last_char=='A' || last_char=='e' || last_char=='E'|| last_char=='i' || last_char=='I' || last_char=='o'|| last_char=='O'|| last_char=='u'|| last_char=='U');
        if(check)
            cout<<"Case #"<<i+1<<": "<<kingdom<<" is ruled by Alice"<<endl;
        else
            cout<<"Case #"<<i+1<<": "<<kingdom<<" is ruled by Bob"<<endl;

    }
    return 0;
}
