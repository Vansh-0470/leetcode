class Solution {
public:
    bool isnumber(char a ){
        if(a=='0'||a=='1'||a=='2'||a=='3'||a=='4'||a=='5'||a=='6'||a=='7'||a=='8'||a=='9')return true ;
        else return false ;
    }
   int pre(char a){
    if(a=='+')return 1;
    else if(a=='-')return 1 ;
   else  if(a=='*')return 2 ;
    else return 2;
   }
    int calculate(string s) {
        stack<int>number ;
        stack<char>operation;
        for(int i =0;i<s.length();i++){
            if(s[i]==' ')continue ;
            else if (isnumber(s[i])){
            string a ;
            while(i<s.length() && isnumber(s[i])){
                a.push_back(s[i]);
                i++;
            }
            i--;
            int j =stoi(a);
            number.push(j);
           }
           else {
               if(operation.empty()){
                operation.push(s[i]);
               }
               else {
                while (!operation.empty() &&pre(operation.top()) >= pre(s[i])) {
                    
                  int y=number.top();
                  number.pop();
                  int x =number.top();
                  number.pop();
                   int result ;
 if(operation.top()=='*'){
                    result =x*y;
                  }
                 else if(operation.top()=='/') {
                    result =x/y;
                 }
                  else if(operation.top()=='+') {
                    result =x+y;
                 }
                  else {
                    result =x-y;
                 }
                 number.push(result);
                 operation.pop();
                     
                
                }
                 operation.push(s[i]);
                
               }
           }
        }
        while(!operation.empty()){
             int y=number.top();
                  number.pop();
                  int x =number.top();
                  number.pop();
                   int result ;
                  if(operation.top()=='*'){
                    result =x*y;
                  }
                 else if(operation.top()=='/') {
                    result =x/y;
                 }
                  else if(operation.top()=='+') {
                    result =x+y;
                 }
                  else {
                    result =x-y;
                 }
                 number.push(result);
                 operation.pop(); 
        }
        int ans =number.top();
        return ans ;
    }
};