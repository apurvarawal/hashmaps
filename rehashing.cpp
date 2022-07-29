#include<bits/stdc++.h>
using namespace std;

struct mapnode{
    
    string key;
    int value;
    mapnode* next;

    mapnode(string key, int value){
        this->key = key;
        this->value = value;
        next = NULL;
    }

    ~mapnode(){
        delete next;
    }
};

struct mymap{
    mapnode** buckets;
    int LLsize;
    int arraysize;

    mymap(){
        buckets = new mapnode*[arraysize];
        LLsize = 0;
        arraysize = 5;

        for(int i=0; i<arraysize; i++){
            buckets[i] = NULL;
        }
    }

    void rehash(){
        mapnode** temp = buckets;
        buckets = new mapnode* [2*arraysize];
        int prevarraysize = arraysize;
        arraysize = 2*arraysize;
        LLsize = 0;

        for(int i=0; i<arraysize; i++){
            buckets[i] = NULL;
        }

        for(int i=0; i<prevarraysize; i++){
            mapnode* head = temp[i];
            while(!head){
                string key = head->key;
                int value = head->value;
                insert(key, value);
                head = head->next;
            }
        }

        //deleting the space occupied by temp
        for(int i=0; i<prevarraysize; i++){
            mapnode* head = temp[i];
            delete head;
        }

        delete [] temp;
    }

    int getbucket(string key){
        int hashcode = 0;
        int currentCoeff = 1;

        for(int i = key.length(); i>=0; i--){
            hashcode += key[i] * currentCoeff;
            hashcode = hashcode % arraysize;
            currentCoeff *= 31;
            currentCoeff = currentCoeff % arraysize;
        }
        return (hashcode % arraysize);
    }

    void insert(string key, int value){
        int bucket = getbucket(key);
        mapnode* head = buckets[bucket];
        while(!head){
            if(head->key == key){
                head->value = value;
                return;
            }
            head = head->next;
        }
        head = buckets[bucket];
        mapnode* n = new mapnode(key, value);
        n->next = head;
        head = n;
        LLsize++;

        double loadfactor = (1.0 * LLsize)/arraysize;
        if(loadfactor>0.7){
            rehash();
        }
    }
};

int main(){
    mymap M;
    M.insert("abc",1);
    M.insert("uit",6);
    M.insert("ytr",10);
    M.insert("lmo",7);
    M.insert("tre",9);
    M.insert("ioe",4);

    return 0;
}