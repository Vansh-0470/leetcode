class Solution {
public:
// can make a visited array instead of count everytime
    bool update(int n , vector<int>&ans, int num){
      if(n==ans.size()){
        return true ;
      }
      if(ans[n]!=-1){
        return update(n+1,ans,num) ;
      }
      for(int i =num;i>0;i--){
           if (count(ans.begin(), ans.end(), i) > 0)
        continue;
               if(i==1){
                ans[n]=1;
               // return true  ;
                if(update(n+1,ans,num)) return true  ;
                ans[n]=-1;
               }
               else {
               
                if(i+n<ans.size()&&ans[i+n]==-1){
                     ans[n]=i;
                      ans[i+n]=i;
                    if(update(n+1,ans,num))  {
                      return true;
                    }
                   ans[n]=-1;
                      ans[i+n]=-1;
                     
                }
               
               } 
            
           
      }
      return false ;

    }
    vector<int> constructDistancedSequence(int n) {
        int size =(n-1)*2+1;
        vector<int>ans(size,-1);
        update(0,ans,n);
        return ans ;
    }
};