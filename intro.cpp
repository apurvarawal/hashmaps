#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map <string,int> map;
    map["abc"] = 1;
    map["def"] = 2;
    cout<<map["abc"]<<endl;
    cout<<map.at("def")<<endl;
    //cout<<map.at("efg")<<endl; //since we have not inserted "efg" in the map, so it doesn't have any value and it will give an error.
    cout<<map["efg"]<<endl; // this will insert "efg" in the map, and then give it a '0' value and cout it.

    //for size
    cout<<map.size()<<endl;

    //check presence
    if(map.count("ghi")>0){
        cout<<"ghi is present"<<endl;
    }
    else{
        cout<<"ghi not present"<<endl;
    }
    return 0;
}