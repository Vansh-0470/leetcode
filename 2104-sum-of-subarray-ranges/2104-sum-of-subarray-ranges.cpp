class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        stack<int>nxt;
    stack<int>pre;
    vector<int>nxtidx(nums.size(),nums.size());
    vector<int>preidx(nums.size(),-1);
    for(int i =0;i<nums.size();i++){
      if(pre.empty()){
    preidx[i] = -1;
}
else {
    while(!pre.empty() && nums[pre.top()] >= nums[i]){
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
    while(!nxt.empty() && nums[nxt.top()] > nums[i]){
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
    long long  smallest=0 ;
   for(int i =0;i<nums.size();i++){
       smallest= (smallest + (long long)nums[i] *
                  (i - preidx[i]) *
                  (nxtidx[i] - i)) ;
   } 



      stack<int>gnxt;
    stack<int>gpre;
    vector<int>gnxtidx(nums.size(),nums.size());
    vector<int>gpreidx(nums.size(),-1);
    for(int i =0;i<nums.size();i++){
      if(gpre.empty()){
    gpreidx[i] = -1;
}
else {
    while(!gpre.empty() && nums[gpre.top()] <= nums[i]){
        gpre.pop();
    }

    if(gpre.empty()){
        gpreidx[i] = -1;
    }
    else {
        gpreidx[i] = gpre.top();
    }
}
gpre.push(i);
    }
   for(int i =nums.size()-1;i>=0;i--){
 if(gnxt.empty()){
    gnxtidx[i] = nums.size();
}
else {
    while(!gnxt.empty() && nums[gnxt.top()] <nums[i]){
        gnxt.pop();
    }

    if(gnxt.empty()){
        gnxtidx[i] = nums.size();
    }
    else {
        gnxtidx[i] = gnxt.top();
    }
}
gnxt.push(i);
    }
   // reverse(nxtidx.begin(),nxtidx.end());
    long long  largest=0 ;
   for(int i =0;i<nums.size();i++){
       largest = (largest + (long long)nums[i] *
                  (i - gpreidx[i]) *
                  (gnxtidx[i] - i)) ;
   } 
   return largest-smallest;
    }
};