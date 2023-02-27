class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int x=0,y=0 ; //x and y are the box origin
        for (int i = 0 ;i<9 ; i++){
            int kx=0,ky=0; //kx and ky are the variables of a box with a (x,y) origin
            unordered_map<int,int>m ;
            
                
                
            for (int j = 0 ; j<9 ; j++){ // check row
                if (board[i][j]!='.'){
                    m[board[i][j]-46]++ ;
                    if (m[board[i][j]-46]>1)
                        return false ;
                }
                if (board[j][i]!='.'){ // check column
                    m[board[j][i]-36]++ ;
                    if (m[board[j][i]-36]>1)
                        return false ;
                }
                if (board[x+kx][y+ky]!='.'){ // check box
                    m[board[x+kx][y+ky]-26]++ ;
                    if (m[board[x+kx][y+ky]-26]>1)
                        return false ;
                }
                ky++;
                if (ky==3){
                    kx++ ;
                    ky=0 ; 

                }
                
            }
            if (i%3==2){
                y+=3;
                x=0;
            } else {
                x+=3 ;
            }
        }
        return true ;
    }
};