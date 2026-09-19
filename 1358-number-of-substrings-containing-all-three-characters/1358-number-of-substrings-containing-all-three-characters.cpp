// left se counter increase kro jb thk ik char ki freq 0 na ho jae and right ke liye just multiply by n-j as all that subarray satisfies the condition
class Solution {
public:
   bool ischar(char x){
    if(x=='a'||x=='b'||x=='c')return true ;
    else return false ;
   }
    int numberOfSubstrings(string nums) {
        int n = nums.length();
        int i = 0;
        int j = 0;
        int ans = 0;
        vector<bool>v(3,false);
        vector<int>freq(3,0);
        while (j < n) {
             if (ischar(nums[j])){
             v[nums[j]-'a']=true ;
             freq[nums[j]-'a']++;
             }
               
           if (v[0] && v[1] && v[2]) {

                int lefteven = 0;
              //  int righteven = 1;
                //  int temp=i;
                    while (i<n&&(freq[0]!=0&&freq[1]!=0&&freq[2]!=0)) {
                        lefteven++;
                        freq[nums[i]-'a']--;
                        i++;
                    }
                    // while (j < n - 1 && (freq[0]==0||freq[1]==0||freq[2]==0)) {
                    //     righteven++;
                    //     j++;
                    // }
                  
                    ans += lefteven*(n-j);
                    for(int k=0;k<3;k++){
                        if(freq[k]==0){
                       v[k]=false;
                       break;
                        }
                    }
                  
                  // i++;
                
            }
            j++;
          
        }
        return ans;  
    }
};