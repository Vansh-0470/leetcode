// class Solution {
// public:
//     int scheduleCourse(vector<vector<int>>& courses) {
//         sort(courses.begin(),courses.end());
//         int n =courses.size();
//       //  priority_queue<pair<int, int>> q;
//       int maxdead=0;
//         for(int i =0;i<n;i++){
//          maxdead=max(maxdead,courses[i][1]);
//         }
//         int ans=0;int time =0;
//         vector<bool>vis(n,false);
//         while(maxdead>0){
//             bool a=false  ; 
//             for(int i =0;i<n;i++){
//                if(maxdead-courses[i][0]>=0&&courses[i][1]>=maxdead&&!vis[i]){
//                 ans++;
//                 maxdead=maxdead-courses[i][0];
//                 a=true ;
//                 vis[i]=true ;
//                }
//             }
            
//             if(!a)break;
//         }
//           //  int duration =q.top().second;
//            // int deadline=q.top(); 
//             // if(time+duration<=deadline){
//             //   time=time+duration;
//             //   ans++;
//             // }
//             // for(int i =0;i<n;i++){
//             //     if(time+courses[i][0]<deadline&&time+courses[i][0]<courses[i][1]){
//             //         time=time+courses[i][0];
//             //         ans++;
//             //     }
//             // }
          
        
//         return ans ;
//     }
// };

// greedy approach is strt adding courses with minimum deadline if at any point deadline is not matched check the courses u have added and find the course with maximum duration if it is greater than current course then replace them
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        priority_queue<int>q;
        int n =courses.size();
        int ans=0;int time =0;
       for(int i =0;i<n;i++){
        int duration=courses[i][0];
        int deadline=courses[i][1];
         if(time+duration<=deadline){
            q.push(duration);
            time=time+duration;
         }
         else {
            if(!q.empty()&&duration<q.top()){
                time=time-q.top();
                 q.pop();
                 q.push(duration);
                  time=time+duration;
            }
          
         }
       }
       ans=q.size();
        return ans ;
    }
};