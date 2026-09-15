class Solution {
public:
   int expand(string &s, int l, int r) {
    int count =0;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            count++;
            l--;
            r++;
        }
        return count; // no of palindrome
    }
    int countSubstrings(string s) {
       int n =s.length();
       int ans=0;
       for(int i =0;i<n;i++){
        int count1=expand(s,i,i);
        int count2=expand(s,i,i+1);
        //int count2=expand(s,i,i+1);
         ans+=count1+count2;
       }
       return ans ;
    }
};