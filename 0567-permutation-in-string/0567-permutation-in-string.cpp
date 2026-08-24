class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>s1track(26,0);
        vector<bool>present(26,0);
        for(int i=0;i<s1.length();i++ ){
            s1track[s1[i]-'a']++;
             present[s1[i]-'a']=true ;
        }
        vector<int>reset(26,0);
        reset=s1track;
        int n =s1.length();
        for(int i =0;i<s2.length();i++){
          
            if(!present[s2[i]-'a'])continue;
            int j =i;
            int size =j+n;
            if(size>s2.length())return false ;
            int remaining=n;
            while(j<size){
           // if not preset then strt with char after that
                if(!present[s2[j]-'a']){
                    i=j;
                    s1track=reset;
                    break;
                }
                // decrease the count

             else if (s1track[s2[j]-'a']>0){
                s1track[s2[j]-'a']--;
                remaining--;
             }
             // less than zero then restart from removing that neg  freq char
             else {
                int k =i;
                while(k<s2.length()){
                    if(s2[k]==s2[j])break;
                    k++;
                }
                i=k;
                s1track=reset;
                break;
             }
             j++;
            }
        //     int sum =0;
        //    for(int m=0;m<26;m++){
        //       sum+=s1track[m];   
        //    }  
        //    if(sum==0)return true ;
         if(remaining == 0)
                return true;
        }
        return false ;
    }
};