#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_set>
using namespace std;
static int FRAME = 3;
static int FAULT = 0 ;
static int HIT = 0 ;
int main(){
    int arr[] = {7,0,1,2,0,3,0,4,2,3,0,3,2,1,2,0,1,7,0,1};
    int size = sizeof(arr)/sizeof(int);
    cout<<size<<"  \n";
    vector<int> v(arr,arr+size);
    queue<int> q;
    unordered_set<int> s;
    for(int i = 0 ; i < v.size(); i++){
        if(s.size()<FRAME){
            if(s.find(v[i]) == s.end()){
                s.insert(v[i]);q.push(v[i]);
                FAULT++;
            }
        }
        else {
            if(s.find(v[i]) == s.end()){
            int val = q.front();
            q.pop();
            s.erase(val);
            q.push(v[i]);   s.insert(v[i]);
            FAULT++;
            }
        }        
    }


    cout<<"FAULT: "<<FAULT << " HIT: "<<v.size()-FAULT;

    return 0;
}