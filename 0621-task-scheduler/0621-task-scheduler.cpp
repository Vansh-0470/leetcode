// at every point  i need char with highe frequency so pq is used 
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>freq(26,0);
        for(int i =0;i<tasks.size();i++){
           freq[tasks[i]-'A']++;
        }
        int count =0;
        int help=n;
   priority_queue<int>q;
 //sort(freq.begin(), freq.end(), greater<>());
 
  for(int i =0;i<26;i++){
    if(freq[i]!=0){
        q.push(freq[i]);
    }
  }
      
       while(!q.empty()){
        //  for(int i =0;i<26;i++){
        //     if(freq[i]!=0){
        //         count++;
        //         freq[i]--;
        //         n--;
        //         if(n==-1)break;
        //     }
        //  }
        vector<int>check;
        while(!q.empty()&&q.top()!=0){
            int i=q.top();
            q.pop();
            if(i!=0){
                 i--;
                check.push_back(i);
            count++;
             n--;
            if(n==-1)break;
            }
        }
        for(int k=0;k<check.size();k++){
            q.push(check[k]);
        }

         if(q.empty()||q.top()==0)return count;
         if(n>=0){
            count=count+n+1;
         }
         n=help;
       }
       return count;
    }
};