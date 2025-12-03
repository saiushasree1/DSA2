#include <bits/stdc++.h>
using namespace std;

bool comp(pair<long long,long long>&a,pair<long long,long long>&b){
  if(a.second != b.second)
    return a.second < b.second; 
  return a.first > b.first;
}
int main() {
    int t;
    cin>>t;
    while(t--){
      long long n,p;
      cin>>n>>p;
      vector<pair<long long,long long>> v(n);
      for(long long i=0;i<n;i++){
        cin>>v[i].first;
      }
      for(long long i=0;i<n;i++){
        cin>>v[i].second;
      }
      sort(v.begin(),v.end(),comp);
      long long cost=p;
      long long ni=1;
      for(long long i=0;i<n;i++){
        if(i<ni && v[i].second<p){
          int x=min(v[i].first,n-ni);
          ni+=x;
          cost+=(x*v[i].second);
        }
        else if(v[i].second>=p) break;
        if(ni==n) break;
      }
      if(ni!=n){
        cost+=p*(n-ni);
      }
      cout<<cost<<endl;
    }
    return 0;
}
