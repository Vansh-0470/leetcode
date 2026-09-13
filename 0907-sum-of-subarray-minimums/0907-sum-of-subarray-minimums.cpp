// think of nxt smaller element and prev smaller element 

class Solution {
public:
long long mod = 1e9 + 7;
    int sumSubarrayMins(vector<int>& nums) {
    stack<int>nxt;
    stack<int>pre;
    vector<int>nxtidx(nums.size(),nums.size());
    vector<int>preidx(nums.size(),-1);
    for(int i =0;i<nums.size();i++){
      if(pre.empty()){
    preidx[i] = -1;
}
else {
    while(!pre.empty() && nums[pre.top()] > nums[i]){
        pre.pop();
    }

    if(pre.empty()){
        preidx[i] = -1;
    }
    else {
        preidx[i] = pre.top();
    }
}
pre.push(i);
    }
   for(int i =nums.size()-1;i>=0;i--){
 if(nxt.empty()){
    nxtidx[i] = nums.size();
}
else {
    while(!nxt.empty() && nums[nxt.top()] >= nums[i]){
        nxt.pop();
    }

    if(nxt.empty()){
        nxtidx[i] = nums.size();
    }
    else {
        nxtidx[i] = nxt.top();
    }
}
nxt.push(i);
    }
   // reverse(nxtidx.begin(),nxtidx.end());
    long long  ans=0 ;
   for(int i =0;i<nums.size();i++){
       ans = (ans + (long long)nums[i] *
                  (i - preidx[i]) *
                  (nxtidx[i] - i)) % mod;
   }
   return ans ;
    }
};