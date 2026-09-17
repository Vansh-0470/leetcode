// find the right even number and left even numbers 
class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int ans = 0;
        while (j < n) {
             if (nums[j] % 2 != 0)
                k--;
            if (k == 0) {

                int lefteven = 1;
                int righteven = 1;
               
                    while (nums[i] % 2 == 0) {
                        lefteven++;
                        i++;
                    }
                    while (j < n - 1 && nums[j + 1] % 2 == 0) {
                        righteven++;
                        j++;
                    }
                  
                    ans += righteven * lefteven;
                   k++;
                   i++;
                
            }
            j++;
          
        }
        return ans;
    }
};
