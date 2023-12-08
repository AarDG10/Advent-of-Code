#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<stdlib.h>
#include<math.h>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll sum=0;
    int k=0,flag=0;
    string s;
    vector<string>v;
    getline(cin,s);
    while(s!="AARD")
    {
        v.push_back(s);
        getline(cin,s);
    }
    vector<int>time,dist;
    for(int i=0;i<2;i++)
    {
        string a=v[i];
        for(int j=0;j<a.size();j++)
        {
            if(i==0)
            {
                if(a[j]>=48 && a[j]<=57)
                {
                    time.push_back(a[j]-48);
                }
            }
            else
            {
                if(a[j]>=48 && a[j]<=57)
                {
                    dist.push_back(a[j]-48);
                }
            }
        }
    }
    ll check=0;
    ll cnt=0;
    ll t=0,d=0;
    for(int i=0;i<time.size();i++)
    {
        t+=(time[i])*pow(10,time.size()-i-1);
    }
    for(int i=0;i<dist.size();i++)
    {
        d+=(dist[i])*pow(10,dist.size()-i-1);
    }
    cout<<t<<" "<<d<<endl;
    ll total=t;
    while(t--)
    {
        ll avg=(total-cnt)*cnt;
        if(avg>d) check++;
        cnt++;
    }
    cout<<check<<endl;
    return 0;
}
