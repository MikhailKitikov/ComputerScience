#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int t,n,x=0;
    cin>>n;
    for (int i=0; i<n; i++)
    {
        cin>>t>>s;
        if (x==0 && s!="South")
        {
            cout<<"NO";
            return 0;
        }
        if (x==20000 && s!="North")
        {
            cout<<"NO";
            return 0;
        }
        if (s=="North")
            x-=t;
        if (s=="South")
            x+=t;
        if (x>20000 || x<0)
        {
            cout<<"NO";
            return 0;
        }
    }
    if (x)
        cout<<"NO";
    else
        cout<<"YES";
	return 0;
}