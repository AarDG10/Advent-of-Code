#include<iostream>
#include<vector>
#define ll long long
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll sum=0;
    string s;
    cin>>s;
    while(s!="AARD")
    {
        vector<int>v;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>=48 && s[i]<=57)
            {
                int k=(int) (s[i]-48);
                v.push_back(k);
            }
        }
        if(v.size()>0)
        {int num=v.front()*10;
        num+=v.back();
        sum+=num;
        }
        cin>>s;
    }
    cout<<sum<<endl;
    return 0;
}
