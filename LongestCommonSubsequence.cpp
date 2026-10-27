class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.length();
        int n2 = text2.length();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
      // không lấy 0 vì xem 0 là chuỗi rỗng
        for (int i=1; i<n1+1;i++ ){
            for(int j=1; j<n2+1;j++){
              // nếu trùng thì +1 vào tổng
                if(text1[i-1]==text2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                  //ko thì lấy hướng dịch nào có tổng lớn hơn
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }

        }
        return dp[n1][n2];
        
    }
};

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size();
        int n = text2.size();

        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i == m || j == n)
                return 0;

            if (text1[i] == text2[j])
              // nếu trùng thì +1 vào tổng
                return 1 + dfs(i + 1, j + 1);
          
              //ko thì lấy hướng dịch nào có tổng lớn hơn
            return max(
                dfs(i + 1, j),
                dfs(i, j + 1)
            );
        };

        return dfs(0, 0);
    }
};
/*
ý tưởng ban đầu so sánh từng ký tự, nếu giống thì trả về +1 điểm, không thì dịch thử ở 1 trong hai chuỗi rồi xét xem cách dịch ở chuỗi nào có tổng điểm lớn hơn.
Sử dụng được đệ quy vì khi thử một lựa chọn, lại gặp đúng bài toán ban đầu nhưng với hai vị trí mới. 
Ban đầu cần tìm LCS từ vị trí (0,0).
Sau khi bỏ a, lại cần tìm LCS từ vị trí (1,0).
Sau khi bỏ b, lại cần tìm LCS từ vị trí (0,1).
Cả ba đều là cùng một bài toán, chỉ khác vị trí bắt đầu.
Cho từng nhánh tự tính nên dùng return thay vì set cứng biến 

text1 = "abc"
text2 = "adc"

So sánh a và a:
-> Giống nhau: +1 điểm
-> Dịch cả hai vị trí

So sánh b và d:
-> Khác nhau: thử 2 cách

  Cách 1: Bỏ b, tiếp tục tìm → được 1 điểm
  Cách 2: Bỏ d, tiếp tục tìm → được 1 điểm

-> max(1, 1) = 1

Tổng = 1 + 1 = 2
*/
