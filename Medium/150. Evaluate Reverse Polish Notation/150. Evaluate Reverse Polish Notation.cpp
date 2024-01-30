class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s ;
        if (tokens.size() == 1)
            return stoi(tokens[0]);
        s.push(stoi(tokens[0])) ;
        int i = 1 ;
        while (i<tokens.size()){
            if (tokens[i] == "/" || tokens[i] == "*" || tokens[i] == "+" ||tokens[i] == "-"){
                int var = s.top() ;
                s.pop() ;
                int var2 = s.top() ;
                s.pop() ;
                if (tokens[i] == "/")
                    s.push(var2 / var) ;
                if (tokens[i] == "+")
                    s.push(var2 + var) ;
                if (tokens[i] == "*")
                    s.push(var2 * var) ;
                if (tokens[i] == "-")
                    s.push(var2 - var) ;
            }
            else{
                s.push(stoi(tokens[i]));
            }
            i++ ;
        }
        return s.top() ;
    }
};