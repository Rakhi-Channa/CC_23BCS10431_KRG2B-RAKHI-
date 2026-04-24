#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	string s;
	map<string,int> mp;
	
	for(int i=0;i<n;i++){
	    cin>>s;
	    mp[s]++;
	}
	string ans;
	int maxgoal=0;
	for(auto it: mp){
	    if(it.second > maxgoal){
	        maxgoal=it.second;
	        ans=it.first;
	    }
	}
	cout<<ans<<endl;

}