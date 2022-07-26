#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map <int, bool> present;
    int n;
    cin>>n;
    int inputVal;
    vector<int> input;
    for(int i=0; i<n; i++){
        cin>>inputVal;
        input.push_back(inputVal);
    }

    for(int i=0; i<n; i++){
        if(present[input[i]]==false){
            cout<<input[i]<<" ";
        }
        present[input[i]]=true;
    }

    return 0;
}