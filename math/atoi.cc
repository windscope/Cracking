#include <iostream>
#include <string>
#include <cassert>
#include <climits>

using namespace std;

class Solution {
public:
    const static char ZERO = '0';
    const static char WHITE_SPACE = ' ';
    const static char POSITIVE_SIGN = '+';
    const static char NEGATIVE_SIGN = '-';
    const static int LONGEST_INT_LENGTH = 11;

    // convert character to integer
    int char2i(const char c) {
        int i = c - ZERO;
        if (i > 9 || i < 0) {
            return -1;
        } else {
            return i;
        }
    }

    int myAtoi(const std::string& input) {
        int64_t output = 0;
        int sign = 1;
        uint32_t start = 0;
        uint32_t input_length = input.length();
        if (input_length == 0) {
            // if empty return 0
            return 0;
        }
        // Escape the white spaces
        while (input[start] == WHITE_SPACE) {
            start++;
        }
        // Get the sign if exist
        if (input[start] == POSITIVE_SIGN) {
            start++;
        } else if (input[start] == NEGATIVE_SIGN) {
            sign = -1;
            start++;
        }
        // Escape the 0s
        while (input[start] == ZERO) {
            start++;
        }
        int single_digit = 0;
        int digit_count = 0;
        // Start convert
        for (uint32_t i = start; i < input.length(); ++i) {
            single_digit = char2i(input[i]);
            // Break if invalid digit or exceed the max length of a valid int32_t
            if (single_digit >= 0 && digit_count <= LONGEST_INT_LENGTH) {
                output = output*10 + single_digit;
                digit_count++;
            } else {
                break;
            }
        }
        output *= sign;
        if (output > INT_MAX) {
            return INT_MAX;
        } else if (output < INT_MIN) {
            return INT_MIN;
        } else {
            return output;
        }
    }
};

int main() {
    const std::string data1 = "              12345";
    const std::string data2 = "";
    const std::string data3 = "0";
    const std::string data4 = "-1";
    const std::string data5 = "123dewdwj";
    const std::string data6 = "12345678910";
    const std::string data7 = "   +004500";
    Solution s;
    assert(s.myAtoi(data1) == 12345);
    assert(s.myAtoi(data2) == 0);
    assert(s.myAtoi(data3) == 0);
    assert(s.myAtoi(data4) == -1);
    assert(s.myAtoi(data5) == 123);
    assert(s.myAtoi(data6) == INT_MAX);
    assert(s.myAtoi(data7) == 4500);
    std::cout << "You Passed!" << endl;
    return 0;
}
