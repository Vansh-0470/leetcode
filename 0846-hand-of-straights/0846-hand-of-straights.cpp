// class Solution {
// public:
//     bool isNStraightHand(vector<int>& nums, int groupSize) {
//         if(nums.size()%groupSize!=0)return false ;
//    

// // could also be done using map 
//         priority_queue<int,vector<int>,greater<int>>q; 
//         int x =groupSize;
//          for(int i =0;i<nums.size();i++){ 
//            q.push(nums[i]);
//          } 
//          int pre =-2;int i =0;
//        while(!q.empty()){
//              if(i%x==0&&i!=0){
//                 pre=-2;
//              }
//              if(pre==-2){
//                  pre=q.top();
//                  q.pop();
//                  i++;
//              }
//              else if (q.top()-pre==1){
//                 pre=q.top();
//                 q.pop();
//                 i++;
//              } 
//              else  {
//                 vector<int>help;
//                 while(!q.empty()){
//                     if(q.top()-pre==1)break;
//                     help.push_back(q.top());
//                     q.pop();
//                 }
//                 if(q.empty())return false ;
//                 else {
//                     pre=q.top();
//                     q.pop();
//                     i++;
//                     for(int k =0;k<help.size();k++){
//                         q.push(help[k]);
//                     }
//                 }
//              }
           
//        }
//        return true ;  
//     }
// };



// optimised soln 
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0){
            return false;
        }
        map<int,int> mpp;
        for(int i:hand){
            mpp[i]++;
        }
        while(!mpp.empty()){
            int x=mpp.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(mpp.find(x+i)==mpp.end()){
                    return false;
                }
                if(--mpp[x+i]==0){
                    mpp.erase(x+i);
                }
            }
        }
        return true;
    }
};