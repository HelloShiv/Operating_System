#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

using namespace std;
static int FRAME = 3;
static int FAULT = 0;
int main(){
    int arr[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int size = sizeof(arr)/sizeof(int);
    cout<<size<<"  \n";
    vector<int> v(arr,arr+size);
    unordered_set<int> s;
    
    unordered_map<int,int> indexes;
    int i = 0 ;
    for( i = 0 ; i < v.size(); i++){
        if(s.size() < FRAME){
            if(s.find(v[i]) == s.end()){
                s.insert(v[i]);
                FAULT++;
            }
            // indexes.insert({v[i],i});
            indexes[v[i]] = i;
        }
        else{
            int LRU = 999;
            if(s.find(v[i]) == s.end()){
                FAULT++;
                 unordered_set<int>::iterator it = s.begin();
                 for( unordered_set<int>::iterator it= s.begin(); it != s.end() ; it++ ){     //POINTER cannot be done like ptr < another_pointer
                    if(*it < LRU){
                        LRU = indexes[v[i]];
                    }
                }
                s.erase(*it);
                s.insert(v[i]);
                // indexes.insert({v[i],i});
                indexes[v[i]] = i;
            }
            // indexes.insert({v[i],i});
            indexes[v[i]] = i;
        }
    }

    cout<<"FAULT: "<<FAULT << " HIT: "<<v.size()-FAULT;
    

    return 0;
}