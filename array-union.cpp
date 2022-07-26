#include<bits/stdc++.h>
using namespace std;
int main(){
    int m;
    cin>>m;
    int inputm;
    vector<int> v1;
    for(int i=0; i<m; i++){
        cin>>inputm;
        v1.push_back(inputm);
    }

    int n;
    cin>>n;
    int inputn;
    vector<int> v2;
    for(int i=0; i<n; i++){
        cin>>inputn;
        v2.push_back(inputn);
    }

    set <int> s;

    for(int i=0; i<m; i++){
        s.insert(v1[i]);
    }

    for(int i=0; i<n; i++){
        s.insert(v2[i]);
    } 


    for(int i:s){
        cout<<i<<" ";
    }

    return 0;
}