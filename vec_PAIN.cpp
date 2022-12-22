#include<iostream>
#include<vector>
#include<algorithm>

static int competion_time;
class Process{
    private:
    int burst_time,waiting_time,arrival_time;
    int turn_around_time;
    public:

    Process(int bt, int at){
        burst_time = bt;
        arrival_time = at;
    }
    // void setter(int at, int bt){
    //     if()
    // }

    void print(){
        std::cout<<"\nArrival Time: "<<arrival_time<<" Burst Time: "<<burst_time;
    }
    static bool comparator(Process P1 , Process P2){
        return P1.arrival_time < P2.arrival_time;   
    }
};


using namespace std;
int main(){
    
    int number,at,bt;     //number of process
    cout<<"Enter number of Process: ";
    cin>>number;
    vector<Process> list;
    for(int i = 0 ; i < number ; i++){
        cout<<"\nEnter Arrival Time and Burst Time: ";
        cin>>at>>bt;
        Process p1(bt,at);
        // p1.setter(at,bt);
        list.push_back(p1);
        

    }
    
    sort(list.begin() , list.end(), Process::comparator);

    for(auto i : list)
        i.print();


    return 0;
}