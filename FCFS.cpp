#include<bits/stdc++.h>
#define vi vector<ll>
#define pb push_back
#define i2n (ll i=0;i<n;i++)
#define j2n (ll j=0;j<n;j++)
#define n2i (ll i=n-1;i>=0;j--)
#define n2j (ll j=n-1;j>=0;j--)
#define full(vec) vec.begin(),vec.end()
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

typedef long long ll;
using namespace std;
void solve()
{
    cout<<"how many process?"<<endl;
    ll n;cin>>n;
    vector<pair<ll,pair<ll,ll>>> time;
    for(ll i=0;i<n;i++) 
    {
        cout<<"Enter arrival time for process "<<i+1<<endl;
        ll a;
        cin>>a;
        cout<<"Enter brust time for process "<<i+1<<endl;
        ll b;
        cin>>b;
        time.push_back({a,{b,i+1}});
    }
    sort(full(time));
    if(time[0].first) cout<<"0 -- ";
        for(ll i=0;i<n;i++)
        {
            
            if (!i)
            {
                cout<<time[i].first<<" p"<<time[i].second.second<<" "<<time[i].first+time[i].second.first<<" ";
                time[i].second.first=time[i].first+time[i].second.first;
            }
            else if(time[i].first>time[i-1].second.first){ 
                    cout<<" -- "<<time[i].first<<" ";
                    cout<<" p"<<time[i].second.second<<" "<<time[i].first+time[i].second.first<<" ";
                    time[i].second.first=time[i].first+time[i].second.first;
                }
            else{ 
                    cout<<" p"<<time[i].second.second<<" "<<time[i-1].second.first+time[i].second.first<<" ";
                    time[i].second.first=time[i-1].second.first+time[i].second.first;
                }
        }
        cout<<endl;
}
int main()
{   
    fast;
    //ll tc;cin>>tc;while(tc--)
    solve();
    return 0;
}
