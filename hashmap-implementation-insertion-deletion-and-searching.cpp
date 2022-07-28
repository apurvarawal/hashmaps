#include<bits/stdc++.h>
using namespace std;

class mapnode{
    public:
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

class mymap{
    public:
    mapnode** buckets; //the first '*' points to the head of the LL, the second represents the buckets array.
    //if we took template, then we would have written the above line of code as :
    //mapnode<T>** buckets;
    int LLsize; //LL inside a bucket
    int arraysize; //array size

    mymap(){
        LLsize = 0;
        arraysize = 5;
        buckets = new mapnode*[arraysize]; //bucket will be equal to head of bucketarray
        //initally all buckets will have garbage value, so we need to initialise it.

        for(int i=0; i<arraysize; i++){
            buckets[i] = NULL; //since every bucket contains a LL, therefore we are initialising each bucket with NULL.
        }
    }

    ~mymap(){
        for(int i=0; i<arraysize; i++){
            delete buckets[i];
        }
        delete [] buckets; //after deleting all the values of the array, we can delete the now empty array too.
    }

    private:
    int getbucketidx(string key){
        int hashcode = 0; //this will be the sum of all the values, coming after the multiplication for separate chaining.

        int currentCoeff = 1;

        for(int i=key.length()-1; i>=0; i--){
            hashcode += key[i] * currentCoeff;
            hashcode = hashcode % arraysize;
            currentCoeff *= 37;
            currentCoeff = currentCoeff % arraysize;
        }

        return hashcode % arraysize;
    }

    public:
    void insert(string key, int value){
        int bucketidx = getbucketidx(key);
        mapnode* head = buckets[bucketidx]; //since we are starting the LL, on the bucketidx index.
        while(!head){
            if(head->key==key){ //we will check if the exists or not, if it exists, then we will simply update the value for that key.
                head->value = value;
                return;
            }
        }
        head = buckets[bucketidx];
        mapnode* n = new mapnode(key,value);
        n->next = head;
        head = n;
        LLsize++;
    }

    void search(string key){
        int bucketidx = getbucketidx(key);
        mapnode* head = buckets[bucketidx];
        while(!head){
            if(head->key == key){
                cout<<head->value<<endl;
            }else{
                cout<<0<<endl;
            }
            head = head->next;
        }
        return;
    }

    void remove(string key){
        int bucketidx = getbucketidx(key);
        mapnode* head = buckets[bucketidx];
        mapnode* prev = NULL;
        while(!head){
            if(head->key == key){
                if(prev == NULL){
                    buckets[bucketidx] = head->next; // if prev = NULL, it means that we want to remove the head which is the bucket itself.
                }else{
                    prev->next = head->next;
                }
                int ans = head->value; //storing the value to return it afterwards.
                head->next=NULL; //so that the whole list after head is not deleted.
                delete head; //deleting the space occupied by head.
                LLsize--;
                cout<<ans<<endl;
            }else{
                cout<<0<<endl;
            }
            prev = head;
            head = head->next;
        }
        return;
    }
};

int main(){
    mymap M;
    M.insert("abc",9);
    M.insert("uit",90);
    M.insert("ytr",45);
    M.insert("lmo",21);
    M.insert("tre",6);
    M.insert("ioe",78);

    M.search("MOU");
    M.search("uit");

    cout<<"yeah";
    M.remove("uit");
    return 0;
}