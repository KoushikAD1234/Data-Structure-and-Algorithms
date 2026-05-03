class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;

        string temp = s + s;

        for (int i = 0; i < temp.size(); i++) {
            int j = i, k = 0;

            while (k < goal.size() && temp[j] == goal[k]) {
                j++;
                k++;
            }

            if (k == goal.size()) return true;
        }

        return false;
    }
};