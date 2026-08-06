class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
      sort(people.begin(),people.end());
      int i =0;
      int count=0;
   //  int ans =0;
      int j =people.size()-1;
      while(i<=j){
        if(i==j){
            count++;
            i++;j--;
            break;
        }

        if(people[j]==limit){
             count++;j--;
        }
      else  if(people[i]+people[j]>limit){
            count++;j--;
        }
        else {
          count++;
            i++;
            j--;
        }
      }
      
       return count;
    }
};