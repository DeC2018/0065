#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        bool isdot = false, nums = false, ise = false;
        for(int i=0; i<n; i++){
            if(isdigit(s[i])) nums = true;
            else if(s[i] == '+' || s[i] == '-'){
                if(i > 0 && (s[i-1] != 'e' && s[i-1] != 'E')) return false;
            }
            else if(s[i] == 'e' || s[i] == 'E'){
                if(ise || !nums) return false;
                ise = true;
                nums = false;
            }
            else if(s[i] == '.'){
                if(isdot || ise) return false;
                isdot = true;
            }
            else return false;
        }
        return nums;
    }
};

int main() {
    Solution sol;
    
    cout << "Input: s = \"0\"" << endl;
    cout << "Output: " << (sol.isNumber("0") ? "true" : "false") << endl;
    
    cout << "Input: s = \"e\"" << endl;
    cout << "Output: " << (sol.isNumber("e") ? "true" : "false") << endl;
    
    cout << "Input: s = \".\"" << endl;
    cout << "Output: " << (sol.isNumber(".") ? "true" : "false") << endl;
    
    return 0;
}
