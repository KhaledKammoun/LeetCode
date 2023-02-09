class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int m = 0 ;
        for (int i = 0 ; i<sentences.size() ; i++){
            std::stringstream ss(sentences[i]);
            string word ;
            int count = 0 ;
            while (ss >> word) {
                count++;
            }
            m=max(m,count) ;
        }
        return m ; 
    }
};