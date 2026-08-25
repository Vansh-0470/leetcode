// this one is o(n^2) it can be optimised to O(26*n) as there are only 26 alphbet so in one loop i can store the last idx of all the char 
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n =s.length();
    int first=0;
    int strt=0;
    int second;
    int idx=INT_MIN;;
    unordered_map<char,int>m;
vector<int>ans;
    while(first<n){
       second=first+1;
       int local=first;
       if(m.find(s[first])==m.end()){
 for(int i =second;i<n;i++){
        if(s[i]==s[first]){
            local=i;
        }
       }
        m[s[first]]=local;
       }
      else {
        local=m[s[first]];
      }
      
       idx=max(local,idx);
       if(idx==n-1){
       ans.push_back(idx-strt+1);
       break;
       }
       first++;
       if(first>idx){
      ans.push_back(idx-strt+1);
     strt=first;
     idx=INT_MIN;
       }
    } 
    return ans ; 



// this one is O(26*n)
// vector<int>help(26,-1);
// for(int i =0;i<n;i++){
//     help[s[i]-'a']=i;
// } 
// int strt=0;
// int end=0;
// vector<int>ans;
//   for(int i =0;i<n;i++){

//             end = max(end,help[s[i] - 'a']);
            
//             if(end == i){
//                 ans.push_back(end-strt+1);
//                 strt = i +1;
//             }
            

//         }
//         return ans ;
    }
};