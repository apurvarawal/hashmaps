#include<bits/stdc++.h>
using namespace std;
int main(){
    unordered_map <string, int> MAP;
    MAP["ABC"] = 1;
    MAP["ABC2"] = 2;
    MAP["ABC3"] = 3;
    MAP["ABC4"] = 4;
    MAP["ABC5"] = 5;

    unordered_map <string,int> :: iterator it = MAP.begin();

    while(it!=MAP.end()){
        cout<< it->first<<" : "<<it->second<<endl;
        it++;
    }

    map <string, int> MAP1;
    MAP1["DEF1"] = 1;
    MAP1["DEF2"] = 2;
    MAP1["DEF3"] = 3;
    MAP1["DEF4"] = 4;
    MAP1["DEF5"] = 5;

    map <string,int> :: iterator it2 = MAP1.begin();

    while(it2!=MAP1.end()){
        cout<< it2->first<<" : "<<it2->second<<endl;
        it2++;
    }

    map<string, int> :: iterator a = MAP1.find("DEF3");
    MAP1.erase(a);

    while(it2!=MAP1.end()){
        cout<< it2->first<<" : "<<it2->second<<endl;
        it2++;
    }

    vector<int> v;
    v.push_back(1);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(0);

    vector <int> :: iterator it1 = v.begin();

    while(it1!=v.end()){
        cout<< *it1<<endl;
        it1++;
    }
    return 0;
}