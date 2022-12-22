#include<iostream>
#include<algorithm>
class Process{
    int arrival , burst_time;
    public:
    Process(){}
    Process(int a , int b){
        arrival = a;
        burst_time = b;
    }
    static bool comp(Process P1 , Process P2){
        return P1.arrival < P2.arrival;
    }
    static void print(Process P){
        std::cout<<" \nArrival Time: "<<P.arrival<<" Burst Time: "<<P.burst_time;
    }

};

using namespace std;

int main(){
    Process *P = new Process[3];
    P[0] = Process(4,3);    P[1] = Process(3,2);    P[2] = Process(2,1);
    vector<Process> v;
    v.push_back(P[0]);v.push_back(P[1]);v.push_back(P[2]);
    sort(v.begin(),v.end(),Process::comp);
    for(int i = 0 ; i < v.size() ; i++)
        Process::print(v[i]);
        
    return 0;
}