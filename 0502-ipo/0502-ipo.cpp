// class Solution {
// public:
//     int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>&
//     capitals) {
//        priority_queue<pair<int,int>>q;
//        int check =w;
//        for(int i =0;i<capitals.size();i++){
//         q.push({profits[i],capitals[i]});
//        }
//        int profit =0;
//        int count =0;
//        while(!q.empty()){
//         if(count==k){
//             return w ;
//         }
//         vector<pair<int,int>>help;
//             while(!q.empty()&&q.top().second>w){
//                 auto it =q.top();
//                  help.push_back(it);
//                  q.pop();
//             }
//             if(q.empty())return w;
//             else {
//                 count++;
//                 profit+=q.top().first;
//                 w=w+q.top().first;
//                 q.pop();
//                 for(auto it :help){
//                     q.push(it);
//                 }
//             }
//        }
//        return  w ;
//     }
// };
// the thing is w is never decreased capital is not consumed it is just basic
// req
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capitals) {

        vector<pair<int, int>> projects;

        for (int i = 0; i < profits.size(); i++) {
            projects.push_back({capitals[i], profits[i]});
        }

        sort(projects.begin(), projects.end());

        priority_queue<int> q;

        int i = 0;

        while (k--) {

            while (i < projects.size() && projects[i].first <= w) {
                q.push(projects[i].second);
                i++;
            }

            if (q.empty())
                break;

            w += q.top();
            q.pop();
        }

        return w;
    }
};