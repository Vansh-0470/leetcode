// class Solution {
// public:
//     double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
//       vector<double>ratio;
//       int n =wage.size();
//        vector<pair<int,int>>help;
//       for(int i =0;i<wage.size();i++){
//         ratio.push_back((double)wage[i]/quality[i]);
//         help.push_back({quality[i],wage[i]});
//       }
    
//        //sort(ratio.begin(),ratio.end());
//   sort(help.begin(),help.end());
//       double ans=DBL_MAX;
//        for(int i =0;i<n;i++){
//         double local=0; int labour=0;
//         for(int j =0;j<n;j++){
//             if(ratio[i]*help[j].first>=help[j].second){
//                // cout<<"heloo";
//                  local+=(double)ratio[i]*help[j].first;
//                  labour++;
//             }
//             if(labour==k)break;
//         }
//         if(local!=0&&labour==k){
//              ans=min(ans,local);
//         }
       
//        }
//       return ans ;              
//     }
// };


class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = wage.size();
        
        // Store (quality, wage) pairs
        vector<pair<int, int>> help;
        for (int i = 0; i < n; i++) {
            help.push_back({quality[i], wage[i]});
        }
        
        // Sort candidates by quality in ascending order
        sort(help.begin(), help.end());
        
        double ans = DBL_MAX;
        
        // Try each worker i as the anchor who sets the group ratio (wage[i] / quality[i])
        for (int i = 0; i < n; i++) {
            int labour = 0;
            long long quality_sum = 0;
            
            for (int j = 0; j < n; j++) {
                // Exact integer cross-multiplication (using long long to prevent integer overflow)
                if (1LL * wage[i] * help[j].first >= 1LL * help[j].second * quality[i]) {
                    quality_sum += help[j].first;
                    labour++;
                    if (labour == k) break;
                }
            }
            
            // Calculate total cost for worker i's ratio if k workers were found
            if (labour == k) {
                double local_cost = ((double)wage[i] / quality[i]) * quality_sum;
                ans = min(ans, local_cost);
            }
        }
        
        return ans;
    }
};