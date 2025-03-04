#include <stdio.h>
#include <string.h>

int isNumber(char* s) {
    int len = strlen(s);
    int num_found = 0;
    int state = 0;  // [1] +-  
                    // [2] num 
                    // [3] .  
                    // [4] num
                    // [5] e/E
                    // [6] +- 
                    // [7] num

    // sanity check
    if (len == 0)
        return 0;

    for (int i=0; i<len; i++) {
        if (state == 0) {
            if ((s[i] == '+') || (s[i] == '-'))
                state = 1;
            else if ((s[i] >= '0') && (s[i] <= '9'))
                state = 2;
            else if (s[i] == '.')
                state = 3;
            else
                return 0;
        }
        else if (state == 1) {
            if ((s[i] >= '0') && (s[i] <= '9'))
                state = 2;
            else if (s[i] == '.')
                state = 3;
            else
                return 0;
        }
        else if (state == 2) {
            if ((s[i] >= '0') && (s[i] <= '9'))
                state = 2; // stay
            else if (s[i] == '.')
                state = 3;
            else if ((s[i] == 'e') || (s[i] == 'E'))
                state = 5;
            else
                return 0;
        }
        else if (state == 3) {
            if ((s[i] >= '0') && (s[i] <= '9'))
                state = 4;
            else if ((s[i] == 'e') || (s[i] == 'E')) {
                if (num_found)
                    state = 5;
                else
                    return 0;
            }
            else
                return 0;
        }
        else if (state == 4) {
            if ((s[i] >= '0') && (s[i] <= '9'))
                state = 4; // stay
            else if ((s[i] == 'e') || (s[i] == 'E'))
                state = 5;
            else
                return 0;
        }
        else if (state == 5) {
            if ((s[i] == '+') || (s[i] == '-'))
                state = 6;
            else if ((s[i] >= '0') && (s[i] <= '9'))
                state = 7;
            else
                return 0;
        }
        else if (state == 6) {
            if ((s[i] >= '0') && (s[i] <= '9'))
                state = 7;
            else
                return 0;
        }
        else if (state == 7) {
            if ((s[i] >= '0') && (s[i] <= '9'))
                state = 7; // stay
            else
                return 0;
        }

        if (state == 2) // number found (needed for some conditions)
            num_found = 1;
    }

    // handle non-valid termination cases
    if ((state == 1) || ((state == 3) && !num_found) || (state == 5) || (state == 6))
        return 0;

    return 1;
}

int main() {
    printf("Input: s = \"0\"\n");
    printf("Output: %s\n", isNumber("0") ? "true" : "false");

    printf("Input: s = \"e\"\n");
    printf("Output: %s\n", isNumber("e") ? "true" : "false");

    printf("Input: s = \".\"\n");
    printf("Output: %s\n", isNumber(".") ? "true" : "false");

    return 0;
}
