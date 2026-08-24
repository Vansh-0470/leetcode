class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
     //   every row and column check 
        for(int i =0;i<9;i++){
            vector<int>rcheck(9,0);
            vector<int>ccheck(9,0);
            for(int j =0;j<9;j++){
                // row check 
                 if(board[i][j]!='.'&&rcheck[board[i][j]-'1']==0){
                    rcheck[board[i][j]-'1']++;
                 }
                 else if (board[i][j]!='.'&&rcheck[board[i][j]-'1']!=0){
                    return false ;
                 }
                 // column check 
                   if(board[j][i]!='.'&&ccheck[board[j][i]-'1']==0){
                    ccheck[board[j][i]-'1']++;
                 }
                 else if (board[j][i]!='.'&&ccheck[board[j][i]-'1']!=0){
                    return false ;
                 }
            }
        }
       // 3X3 matrix check
       for(int m =0;m<3;m++){ 
       for(int i =0;i<3;i++){
        vector<int>mcheck(9,0);
        for(int j=m*3;j<m*3+3;j++ ){
            for(int k =i*3;k<i*3+3;k++){
                 if(board[j][k]!='.'&&mcheck[board[j][k]-'1']==0){
                    mcheck[board[j][k]-'1']++;
                 }
                 else if (board[j][k]!='.'&&mcheck[board[j][k]-'1']!=0){
                    return false ;
                 }
            }
        }
       }
       } 
       return true ;   
    }
};