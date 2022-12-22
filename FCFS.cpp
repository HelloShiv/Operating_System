#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<stdio.h>
using namespace std;
class Process{
    private:
    string name;
    int arrival_time, burst_time, waiting_time, turn_around_time, completion_time;
    public:
    Process(){
        arrival_time = 0 ;
        burst_time = 0 ;
        waiting_time = 0;
        turn_around_time = 0;
        completion_time = 0 ; 
    }
    Process(int &arrival_time, int &burst_time, int i){
        this->arrival_time = arrival_time;
        this->burst_time = burst_time;
        this->name = 'P'+ to_string(i);
    }

    static void print(vector<Process> &temp){
            std::cout<<"\n  Process  Arrival Time    Burst Time     Completion time    Turn Around Time    Waiting Time\n";
        for(auto i: temp)
                 cout<<"\n     "<<i.name<<"      "<<i.arrival_time<<"               "<<i.burst_time<<"                 "<<i.completion_time<<"                  " <<i.turn_around_time<<"                  "<<i.waiting_time;
    }              

    static void setter(vector<Process> &temp){
            static int ct;          //Global ct time;
        for(int i = 0 ; i < temp.size(); i++){
            if(ct == 0)
                ct = temp[i].burst_time;
            else if(ct < temp[i].arrival_time )
                ct = (temp[i].arrival_time -ct) + temp[i].burst_time + ct;
            else if ( ct > temp[i].arrival_time)
                ct = ct + temp[i].burst_time;
            
            temp[i].completion_time = ct;
            temp[i].turn_around_time = temp[i].completion_time -temp[i].arrival_time;
            temp[i].waiting_time = temp[i].turn_around_time - temp[i].burst_time;
        }
    }
    static bool comp(Process P1, Process P2){
        return P1.arrival_time < P2.arrival_time;
    }
};

int main(){
    int number, arrival_time, burst_time;
    cout<<"Enter number of process: ";
    if(cin>>number);
    vector<Process> P;
    for(int i = 0 ; i < number; i++){
        cout<<"\n Enter Arrival time, Burst Time: ";
        cin>>arrival_time>>burst_time;
        Process temp(arrival_time,burst_time,i);
        P.push_back(temp);
    }
    sort(P.begin(),P.end(),Process::comp);
    Process::setter(P);
    Process::print(P);
    return 0;
}