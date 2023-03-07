class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int>Stack ;
        for (int i = 0 ; i<tokens.size() ; i++){
            if (tokens[i]!="*" && tokens[i]!="/" && tokens[i]!="-" && tokens[i]!="+")
                Stack.push(stoi(tokens[i])) ;
            else {
                int som = Stack.top() ;
                Stack.pop() ;
                if (tokens[i]=="*")
                    som = Stack.top() * som;
                else if (tokens[i]=="/")
                    som = Stack.top() / som;
                else if (tokens[i]=="+")
                    som = Stack.top() + som;
                else 
                    som = Stack.top() - som;
                Stack.pop() ;
                Stack.push(som) ;
            }
        }
        return Stack.top() ;
    }
};