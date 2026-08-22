class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int help;
    KthLargest(int k, vector<int>& nums) {
        if(nums.size()>0){
      for(int i =0;i<nums.size();i++){
        pq.push(nums[i]);
        if(pq.size()>k){
            pq.pop();
        }
      } 
        }
        help=k;
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>help){
          pq.pop();
        }
    //     if(pq.size()<help){
    //         pq.push(val);
    //         return pq.top();
    //     }
    //  else  if(val>pq.top()){
    //     pq.pop();
    //     pq.push(val);
    //    }
       return pq.top();
    }
};

/**;
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */