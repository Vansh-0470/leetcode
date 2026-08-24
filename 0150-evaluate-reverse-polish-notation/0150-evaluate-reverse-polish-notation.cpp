class Solution {
public:
    bool isoperator(string a){
        if(a=="+"||a=="-"||a=="*"||a=="/"){
            return true ;
        }
        else return false;
    }
    int evalRPN(vector<string>& tokens) {
        stack<int>s;
        for(int i =0;i<tokens.size();i++){
           if(!isoperator(tokens[i])){
            int a =stoi(tokens[i]);
            s.push(a);
           }
           else {
            int b =s.top();
            s.pop();
            int a =s.top();
            s.pop();
            int result ;
            if(tokens[i]=="+"){
                result=a+b;
            }
            else if(tokens[i]=="-"){
                result=a-b;
            }
            else if(tokens[i]=="*"){
                result=a*b;
            }
             else{
                result=a/b;
            }
            s.push(result);
           }
        }
        int ans =s.top();
return ans ;
    }
};