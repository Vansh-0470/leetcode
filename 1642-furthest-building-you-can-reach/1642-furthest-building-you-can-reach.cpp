class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
       priority_queue<int,vector<int>,greater<int>>q;
       vector<int>dif;
        for(int i =1;i<n;i++){
          if(heights[i-1]<heights[i]){
         dif.push_back(heights[i]-heights[i-1]);
          }
          else {
            dif.push_back(0);
          }
         
        }
       int ans=0;
       int i =0;
       for( i =0;i<dif.size();i++){
        if(dif[i]==0)continue ;
        //  if(bricks<dif[i]&&ladders<=0){
        //     break;
        //  }
        if(ladders>0){
            q.push(dif[i]);
            ladders--;
            continue ;
        }
        else{
            if(q.empty()){
                if(bricks>=dif[i]){
                    bricks-=dif[i];
                }else break;
            }
            else if (q.top()<dif[i]){
                if(bricks>=q.top()){
                     bricks-=q.top();
                q.pop();
                q.push(dif[i]);
                }
              else {
                break;
              }
            }
            else { 
               if(bricks>=dif[i]){
                bricks-=dif[i];
               }
               else {
                break;
               }
            }

        }
       }
      // if(i==dif.size())return i+1;
       return i;
    }
};