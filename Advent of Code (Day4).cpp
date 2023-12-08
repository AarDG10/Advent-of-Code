#include<iostream>
#include<vector>
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
    getline(cin,s);
    while(s!="AARD")
    {
        int cnt=0;
        map<int,int>m,a;
        int flag=0,sett=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==':')
            {
                sett=1;
            }
            if(s[i]=='|')
            {
                flag=1;
            }
            if(!flag && sett)
            {
                k=0;
                if(s[i]>=48 && s[i]<=57)
                {
                    if(i+1<s.size() && s[i+1]>=48 && s[i]<=57)
                    {
                        k=10*(s[i]-48);
                        k+=(s[i+1]-48);
                        i++;
                    }
                    else
                    {
                        k=(s[i]-48);
                    }
                    m[k]++;
                }
            }
            else if(sett && flag)
            {
                k=0;
                if(s[i]>=48 && s[i]<=57)
                {
                    if(i+1<s.size() && s[i+1]>=48 && s[i]<=57)
                    {
                        k=10*(s[i]-48);
                        k+=(s[i+1]-48);
                        i++;
                    }
                    else
                    {
                        k=(s[i]-48);
                    }
                    a[k]++;
                }
            }
            if(a[k]>0 && m[k]>0)
            {
                cnt++;
                //cout<<k<<" "<<cnt<<endl;
            }
        }
        if(cnt!=0) sum+=pow(2,cnt-1);
        getline(cin,s);
    }
    cout<<sum<<endl;
    return 0;
}
