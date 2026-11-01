class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    int i =0;
    int j =0;
    vector<int>num1(1001,0);
    vector<int>num2(1001,0);
    for(int i =0;i<nums1.size();i++){
        num1[nums1[i]]++;
    }
     vector<int>ans;
     for(int i =0;i<nums2.size();i++){
        num2[nums2[i]]++;
    }
    for(int i =0;i<1001;i++){
        if(num1[i]!=0&&num2[i]!=0){
            ans.push_back(i);
        }
    }
   return ans ;
    
    }
};