#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> v;
    int val;
    for(int i=0; i<n; i++){
        cin>>val;
        v.push_back(val);
    }

    unordered_map<int, int> freq;
    int maxfreq = 0;
    int ele = 0;

    for(int i=0; i<n; i++){
       freq[v[i]]++;
       maxfreq = max(maxfreq,freq[v[i]]);
       if(maxfreq == freq[v[i]]){
            ele = v[i];
       }
    }

    cout<<"Element -> "<<ele<<endl<<"Frequency -> "<<maxfreq;
    return 0;
}