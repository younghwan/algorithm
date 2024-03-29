#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define p pair<int,int>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights){
    queue<p> q;
    int time = -1;
    int exit_cnt = 0;
    int truck_size = (int)truck_weights.size();
    int idx = 0;
    int now_weight = 0;

    while(exit_cnt != truck_size){
        time ++; 
        int q_size = q.size(); 

        for(int i=0; i<q_size; i++){
            int value = q.front().first; 
            int _idx = q.front().second; 
            q.pop();
            value--; 
            if( value == 0 ){
                exit_cnt++;
                now_weight -= truck_weights[_idx];
                continue;
            }
            q.push({value,_idx});
        }

        if( idx < truck_size && q.size() <= bridge_length ){
            if(truck_weights[idx] + now_weight <= weight){
                now_weight += truck_weights[idx];
                q.push({bridge_length,idx});
                idx++;
            }
        }
    }    
    time ++;
    cout << time << endl;

    return time;
}