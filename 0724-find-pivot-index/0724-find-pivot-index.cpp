class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       int sum = 0 ;
        for( int i = 0 ; i < nums.size(); i++)
        sum += nums[i];
        int sum_left =0 ;
        for ( int i = 0 ; i < nums.size() ;i++)
        {
            if( sum_left == (sum -sum_left -nums[i])) 
            return i ;
            
            sum_left +=nums[i];
        }
        
        return -1;
    }
};