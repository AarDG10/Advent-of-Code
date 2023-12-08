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
            else
            {
                int stor=-1;
                if(i+2<s.size() && s[i]=='o' && s[i+1]=='n' && s[i+2]=='e')
                {
                    stor=1;
                    v.push_back(stor);
                    i+=1;
                }
                else if(s[i]=='t' && i+2<s.size() && s[i+1]=='w' && s[i+2]=='o')
                {
                    stor=2;
                    v.push_back(stor);
                    i+=1;
                }
                else if(s[i]=='t' && i+4<s.size() && s[i+1]=='h' && s[i+2]=='r' && s[i+3]=='e' && s[i+4]=='e')
                {
                    stor=3;
                    v.push_back(stor);
                    i+=3;
                }
                else if(i+3<s.size() && s[i]=='f' && s[i+1]=='o' && s[i+2]=='u' && s[i+3]=='r')
                {
                    stor=4;
                    v.push_back(stor);
                    i+=2;
                }
                else if(i+3<s.size() && s[i]=='f' && s[i+1]=='i' && s[i+2]=='v' && s[i+3]=='e')
                {
                    stor=5;
                    v.push_back(stor);
                    i+=2;
                }
                else if(i+2<s.size() && s[i]=='s' && s[i+1]=='i' && s[i+2]=='x')
                {
                    stor=6;
                    v.push_back(stor);
                    i++;
                }
                else if(i+4<s.size() && s[i]=='s' && s[i+1]=='e' && s[i+2]=='v' && s[i+3]=='e' && s[i+4]=='n')
                {
                    stor=7;
                    v.push_back(stor);
                    i+=3;
                }
                else if(i+4<s.size() && s[i]=='e' && s[i+1]=='i' && s[i+2]=='g' && s[i+3]=='h' && s[i+4]=='t')
                {
                    stor=8;
                    v.push_back(stor);
                    i+=3;
                }
                else if(i+3<s.size() && s[i]=='n' && s[i+1]=='i' && s[i+2]=='n' && s[i+3]=='e')
                {
                    stor=9;
                    v.push_back(stor);
                    i+=2;
                }
            }
        }
        if(v.size()>0)
        {
            int num=v.front()*10;
            num+=v.back();
            sum+=num;
        }
        cin>>s;
        // for(auto i:v) cout<<i<<" "; cout<<endl;
    }
    cout<<sum<<endl;
    return 0;
}
