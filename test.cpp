#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class Data{
    public:
    int var;
    Data(int data){
        var = data;
    }
};

bool compBy( Data x ,  Data y){
    return x.var < y.var;
}


int main(){
    vector<Data> v1;
    for(int i = 0 ; i< 5; i++){
        Data temp(i);
        
    }

    sort(v1.begin(),v1.end(),compBy);

    for(auto i: v1){
        cout<<"\n Data: "<<*std::prev(v1.end()).var;
        break;
    }

    
    return 0;
}