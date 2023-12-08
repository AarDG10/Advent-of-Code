#include<iostream>
#include<algorithm>
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
    map<string,string>lmap,rmap;  //string input problem(needs to be resolved so manual input)
    string track="LRLRRRLRRRLLLRLRRLLRLRRRLRLRRRLRLRRRLRLRRRLRRRLRLLRRRLRLRLRRLRRLRLRRLRRLRRLLRRRLRRRLRRLRRLRRLRRRLLRRLRLRRLRLRRLRRLRLRRLRRLLRLRRRLRRLRRRLLRLRLRLLRLLRLLRLRRLLRRLRLRLRRLRLLRRRLLRRRLRRLLRRRLRRRLRLRRRLLRRRLRLRRRLLLRRRLRLRLRRRLRRRLRRRLRLRRLLLRRLRRRLLRLRRRLRLRLLLRRLRLRRRLRLRRRR";
    int sett=0;
    string cmst,c1,c2;
    vector<string>hold;
    for(int i=0;i<v.size();i++)  //mapping
    {
        sett=0;
        string a=v[i];
        flag=0;
        for(int j=0;j<a.size();j++)
        {
            if(!sett && a[j]>=65 && a[j]<=90)
            {
                cmst.push_back(a[j]);
            }
            else if(a[j]=='=')
            {
                sett=1;
            }
            else
            {
                if(a[j]==',')
                {
                    flag=1;
                }
                if(flag && a[j]>=65 && a[j]<=90)
                {
                    c1.push_back(a[j]);
                }
                else if(!flag && a[j]>=65 && a[j]<=90)
                {
                    c2.push_back(a[j]);
                }
            }
        }
        if(cmst.back()=='A')
        {
            hold.push_back(cmst);
        }
        rmap[cmst]=c1;
        lmap[cmst]=c2;
        c1.clear();
        c2.clear();
        cmst.clear();
        //cout<<cmst<<" "<<lmap[cmst]<<" "<<rmap[cmst]<<endl;
    }
    ll cnt=0;
    string::iterator it=track.begin();
    string curr;
    vector<ll>nov;
    for(int i=0;i<hold.size();i++)
    {
        it=track.begin();
        cnt=0;
        curr=hold[i];
        cout<<curr<<endl;
        while(curr.back()!='Z')
        {
            if(*it=='R')
            {
                curr=rmap[curr];
                //if(i==2 && cnt<1000) cout<<curr<<endl;
            }
            else if(*it=='L')
            {
                curr=lmap[curr];
                //if(i==2 && cnt<1000) cout<<curr<<endl;
            }
            if(it==track.end()-1) it=track.begin();
            else it++;
            cnt++;
            if(curr.back()=='Z') cout<<curr<<endl;
        }
        cout<<cnt<<endl;
        nov.push_back(cnt);
    }
    ll ans=nov[0];
    for(int i=1;i<nov.size();i++)
    {
        ans=(nov[i]*ans)/__gcd(nov[i],ans);
    }
    cout<<ans<<endl;
    return 0;
}
