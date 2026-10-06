class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
     priority_queue<int>pq;
     for(int i =0;i<stones.size();i++){
        pq.push(stones[i]);
     }  
     while(!pq.empty()){
        if(pq.size()==0)return 0;
        if(pq.size()==1)return pq.top();
        int a =pq.top();
        pq.pop();
        int b =pq.top();
        pq.pop();
        if(a-b!=0){
            pq.push(a-b);
        }
     }
     return 0;
    }
};