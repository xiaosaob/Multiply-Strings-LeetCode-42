// Given two numbers represented as strings, return multiplication of the numbers as a string.

// Note: The numbers can be arbitrarily large and are non-negative.

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0") return "0";
        int n1 = num1.size();
        int n2 = num2.size();
        stringstream ss;
        int sum = 0;
        for(int k = 0; k < n1+n2-1; ++k) {
            for(int i = 0; i <= k; ++i) {
                int j = k-i;
                int ri = n1-1-i;
                int rj = n2-1-j;
                if(ri >= 0 && ri < n1 && rj >= 0 && rj < n2) {
                    sum += (num1[ri]-'0')*(num2[rj]-'0');
                }
            }
            ss<<sum%10;
            sum /= 10;
        }
        if(sum > 0) ss<<sum;
        string res("");
        ss>>res;
        reverse(res.begin(), res.end());
        return res;
    }
};
