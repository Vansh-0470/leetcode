// was initially looking at the left char but (by gpt help) should look at the most frequent char in that window 
// main approach is if window size - mostfreq char is greater than k then shift the window 
class Solution {
public:
    int characterReplacement(string s, int k) {
       unordered_map<char,int>m;
         int left =0;
         int ans=0;
         int j =0;
         int maxfreq=0;
         while(j<s.length()){
            char c =s[left];
            m[s[j]]++;

            maxfreq=max(maxfreq,m[s[j]]);
       
             while((j-left+1)-maxfreq>k){
                m[s[left]]--;
                left++;
             }
            ans=max(ans,j-left+1);
            j++;
         }

         return ans ;
    }
};



