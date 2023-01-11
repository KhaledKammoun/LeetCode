class Solution {
public:
    bool checkIfPangram(string sentence) {
        int t[26]={0} ;
        int l = sentence.length() ;
        for (int i = 0 ; i<l ; i++){
            if (t[sentence[i]-97]==0 )
                t[sentence[i]-97]=1;
        }
        int sum = std::accumulate(t, t+26, 0);
        if (sum==26)
            return true ;
        else
            return false ;
        
    }
};