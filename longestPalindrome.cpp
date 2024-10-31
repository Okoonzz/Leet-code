class Solution {
public:
    string longestPalindrome(string s) {
    int n = s.length();
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    int maxlen = 1;
    for(int i = 0; i < n; i++){
        dp[i][i] = true;
    }

    int start =0;
    for(int i = 0; i < n-1; i++){
        if(s[i] == s[i+1]){
            dp[i][i+1]=true;
            start = i;
            maxlen = 2;
        }
    }

    for(int k = 3; k <= n; k++){
        for(int i = 0; i <= n-k; i++){
            int j = i+k-1;
            if(dp[i+1][j-1] && s[i] == s[j]){
                dp[i][j] =  true;

                if(k > maxlen){
                    start = i;
                    maxlen = k;
                }
            }
        }
    }

    return s.substr(start, maxlen);
    }
};
