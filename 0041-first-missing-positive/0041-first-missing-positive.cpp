class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
    int n =nums.size();
    if(n==1){
        if(nums[0]!=1){
            return 1 ;
        }  
        else return nums[n-1]+1;  
        }
     int write =-1;
     int read =0;
     // got all negatives at left side 
     while(read<n){
        if(nums[read]>0){
            if(write==-1)write=read;  
        }
        else if(write!=-1){
            swap(nums[write],nums[read]);
            write++;
        }
        read++;
     } 
    // get all values at their right idx 
    int offset=1;
    if(write==-1)return 1;
    for(int i =write;i<n;i++){
        if(nums[i]==offset){
     offset++;
continue ;
        }
       
        else {
         
            while(nums[i]!=offset){
                   int check=nums[i];
                if((long long )write+nums[i]-1<n){
                    swap(nums[i],nums[write+nums[i]-1]);
                    if(nums[i]==check)break;
                }
                else {
                    break;
                }
            }

            offset++;
        }
    }
    int ans=1;
 //   cout<<write<<endl;
     for(int i =write;i<n;i++){
      if(nums[i]==ans){
        ans++;
      }
      else {
        return ans ;
      }
     }
   
    //  for(int i =0;i<n;i++){
    //     cout<<nums[i]<<" ";
    //  }
     return nums[n-1]+1; 
    }
};