#include<bits/stdc++.h>
using namespace std;
int main(){
    int m;
    cin>>m;
    int inputm;
    vector <int> v1;
    for(int i=0; i<m; i++){
        cin>>inputm;
        v1.push_back(inputm);
    }

    int n;
    cin>>n;
    int inputn;
    vector <int> v2;
    for(int i=0; i<n; i++){
        cin>>inputn;
        v2.push_back(inputn);
    }

    unordered_map <int, bool> intersect;

    for(int i=0; i<m; i++){
        intersect[v1[i]] = true;
    }

    for(int i=0; i<n; i++){
        if(intersect[v2[i]]==true){
            cout<<v2[i]<<"  ";
        }
        intersect[v2[i]]=false;
    }

    return 0;
}