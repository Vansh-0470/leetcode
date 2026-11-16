class Solution {
public:
  // bit manupulation mere bski nhi h 
// got bit soln from gpt 
// class Solution {
// public:
//     int singleNumber(vector<int>& nums) {

//         int ans = 0;

//         for(int i = 0; i < 32; i++) {
//             int cnt = 0;

//             for(int x : nums) {
//                 if(x & (1 << i)) {
//                     cnt++;
//                 }
//             }

//             if(cnt % 3 != 0) {
//                 ans |= (1 << i);
//             }
//         }

//         return ans;
//     }
// };
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int>s;
        long long  sum =0;
        for(int i =0;i<nums.size();i++){
         // sum+=nums[i];
          s[nums[i]]++;
        }
     for(auto a:s){
        if(a.second==1){
            return a.first;
        }
     }
      return 0;
    }
   
     //  return ans/2;
    
};