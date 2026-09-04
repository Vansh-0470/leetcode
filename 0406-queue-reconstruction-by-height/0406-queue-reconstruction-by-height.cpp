// class Solution {
// public:
//     int insertpos(vector<vector<int>>&check,vector<int>&help){
//         int i =0;int count =0;
//         if(help[1]==0)return check.size();
//         while(i<check.size()){
           
//             if(check[i][0]>=help[0]){
//                count++;
//             }
           
//              if(count>help[1])break;
//               i++;
//         }
//         return i;
//     }
//     vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
//         int n =people.size();
//         vector<vector<int>>ans;
//         priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
//         for(int i =0;i<people.size();i++){
//             pq.push({people[i][1],people[i][0]});
//         }
//         while(!pq.empty()){
//             int height=pq.top().second;
//             int number=pq.top().first;
//            vector<int>help;
//            help.push_back(height);
//            help.push_back(number);
//            int pos =insertpos(ans,help);
//            if(pos==ans.size())ans.push_back(help);
//            else {
//  ans.insert(ans.begin()+pos,help);
//            }  
//            pq.pop();
//         }
//         return ans;
//     }
// };
class Solution {
public:
    int insertpos(vector<vector<int>>&check,vector<int>&help){
        int i =0;int count =0;
        if(help[1]==0)return check.size();
        while(i<check.size()){
           
            if(check[i][0]>=help[0]){
               count++;
            }
           
             if(count>help[1])break;
              i++;
        }
        return i;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n =people.size();
        vector<vector<int>>ans;
        sort(people.begin(), people.end(), [](vector<int>& a, vector<int>& b) {
    if (a[1] == b[1])
        return a[0] < b[0];
    return a[1] < b[1];
       });
       // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
       // for(int i =0;i<people.size();i++){
       //     pq.push({people[i][1],people[i][0]});
       // }
        //while(!pq.empty()){
        for(int i =0;i<n;i++){

        
            int height=people[i][0];
            int number=people[i][1];
           vector<int>help;
           help.push_back(height);
           help.push_back(number);
           int pos =insertpos(ans,help);
           if(pos==ans.size())ans.push_back(help);
           else {
 ans.insert(ans.begin()+pos,help);
           }  
           //pq.pop();
       }
        return ans;
    }
};