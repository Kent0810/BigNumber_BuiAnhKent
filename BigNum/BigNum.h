#pragma once
#include <iostream>
#include <string>
class MyBigNumber {
private:
    void Log(char stn0, char stn1, char stn2, std::string result, std::string carry);

public:
    std::string sum(std::string stn1, std::string stn2);
};

void MyBigNumber::Log(char stn0, char stn1, char stn2, std::string result, std::string carry) {
    std::cout << stn0<<" + " << stn1 << " + " << stn2 << " = " << result << " (carry: " << carry << ")" << std::endl;
}

std::string MyBigNumber::sum(std::string stn1, std::string stn2) {

    std::string result = "";

    // We will add the numbers from the end to the beginning
    // We only need to care about the positive numbers as given that both the parameters are only containing digits 0-9 and no other characters
    int sum = 0, carry = 0;
    int i = stn1.length() - 1;
    int j = stn2.length() - 1;

    char temp0 = '0', temp1 = '0', temp2 = '0';
    while (i >= 0 || j >= 0 || carry > 0) {
        sum = carry;
        temp0 = carry + '0';
        temp1 = '0';
        temp2 = '0';
         // At the beginning of the loop, sum will be the carry from the previous iteration
        if (i >= 0) {
            // We need to subtract '0' to transform the character into an integer
            sum += stn1[i] - '0';
            temp1 = stn1[i];
            i--;
        }
        if (j >= 0) {
            // We need to subtract '0' to transform the character into an integer
            sum += stn2[j] - '0';
            temp2 = stn2[j];
            j--;
        }

        // Store the last digit of the sum in the result
        result = std::to_string(sum % 10) + result;
        // Store the carry for the next iteration
        carry = sum / 10;

        // Log the current iteration
       
        if (i >= 0 && j >= 0) {
            if (stn1[i] == '0' && stn2[j] == 0 && carry == 0) break;
        }

        Log(temp0, temp1, temp2, result, std::to_string(carry));
    }
    // If there is a carry left, we need to add it to the result
    if (carry > 0) {
        result = std::to_string(carry) + result;
    }
    int flag = 0;
    while (result[flag] == '0') {
        result = result.substr(1);
    }
    std::cout << "Final Result = " << result<<'\n';
    return result;
}