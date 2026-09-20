// find the subarray with minimum sum of size n-k
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
     int n =cardPoints.size();
     int ans =0;
     for(int i =0;i<n;i++){
    ans+=cardPoints[i];
}
     if(n==k){
      return ans ;
     } 
      int i =0;
      int j =0;
      int size=n-k;
      int sum=0;
      int mini=INT_MAX;
      while(j<n){
        if(size>0){
          sum+=cardPoints[j];
          size--;
        }
         else {
           // cout<<mini<<endl;
        mini=min(sum,mini);
         sum-=cardPoints[i];
         sum+=cardPoints[j];
         i++;
        
         }
       j++;
      }
    mini=min(sum,mini);
return ans-mini ;
    }
};

// class Solution {
// public:
//     int maxScore(vector<int>& cardPoints, int k) {
//      int n =cardPoints.size();
//      int ans =0;

//      if(n==k){
// for(int i =0;i<n;i++){
//     ans+=cardPoints[i];
// }
// return ans ;
//      } 
//       int i =0;
//       int j =n-1;
//        int localleft=0;
//         for(int x=j;x>j-k;x--){
//             localleft+=cardPoints[x];
//         }
//          int localright=0;
//         for(int x=i;x<i+k;x++){
//             localright+=cardPoints[x];
//         }
//       while(i<j){
//         if(k==0)break;
//         if(localright>localleft){
//             // cout<<cardPoints[j]<<endl;
//             ans+=cardPoints[i];
//             localright-=cardPoints[i];
//             localleft-=cardPoints[j-k-1];
//             i++;

//         }
//         else if(localright<localleft) {
//            // cout<<cardPoints[i]<<endl;
//             ans+=cardPoints[j];
//               localright-=cardPoints[i+k-1];
//             localleft-=cardPoints[j];
//             j--;
//         }
//         else {
//             if(cardPoints[i]>cardPoints[j]){
//                 ans+=cardPoints[i];
//                   localright-=cardPoints[i];
//             localleft-=cardPoints[j-k-1];
//                 i++;
//             }
//             else {
//                 ans+=cardPoints[j];
//                  localright-=cardPoints[i+k-1];
//             localleft-=cardPoints[j];
//                 j--;
//             }
//         }
//         k--;
//       }

// return ans ;
//     }
// };