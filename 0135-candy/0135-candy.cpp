// o(n^2) is brute force gonna think for o(n)soln that include left to right pass  for ascending and right to left pass for desecending(unable to think got it from gpt)

// class Solution {
// public:
//     int candy(vector<int>& ratings) {
//         int n =ratings.size();
//         vector<int>candy(n,1);
//         // for(int i =0;i<n-1;i++){
//         //     if(ratings[i]>ratings[i+1]){
               
//         //             candy[i]=candy[i+1]+1;
                
//         //     }
//         // }
//         // for(int i =n-1;i>0;i--){
//         //     if(ratings[i]>ratings[i-1]){
               
//         //             candy[i]=max(candy[i],candy[i-1]+1);
                
//         //     }
//         // }





//         for(int i =0;i<n-1;i++){
//             if(ratings[i]>ratings[i+1]){
//                 if(candy[i]>candy[i+1])continue;
//                 else  {
//                     candy[i]=candy[i+1]+1;
//                     int j =i;
//                     while(j>0){
//                         if(ratings[j]>=ratings[j-1])break;
//                      if(candy[j]>=candy[j-1]){
//                      candy[j-1]=candy[j]+1;
//                      }
//                      j--;
//                     }
//                 }
//             }
//             else if (ratings[i]<ratings[i+1]){
//                 if(candy[i]<candy[i+1])continue;
//                 else {
//                     candy[i+1]=candy[i]+1;
//                 }
//             }
//             else {
//                 candy[i+1]=1;
//             }
//         }
//        int ans= accumulate(candy.begin(), candy.end(), 0);
//        return ans;
//     }
// };
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candy(n, 1);

        // Left -> Right
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candy[i] = candy[i - 1] + 1;
            }
        }
    
        // Right -> Left
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candy[i] = max(candy[i], candy[i + 1] + 1);
            }
        }

        return accumulate(candy.begin(), candy.end(), 0);
    }
};