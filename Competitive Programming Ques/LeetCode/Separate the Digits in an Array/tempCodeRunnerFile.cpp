class Solution {
   public:
    vector<int> extractNums(int& num) {
        vector<int> temp;
        int p = 10;

        while (num != 0) {
            temp.push_back(num % p);
            num /= p;

            p *= 10;
        }

        reverse(temp.begin(), temp.end());
        return temp;
    }

    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for (auto i : nums) {
            for (auto j : extractNums(i)) {
                ans.push_back(j);
            }
        }

        return ans;
    }
};