class Solution {
public:
    string intToRoman(int num) {

        // 1st approach
        int i = 1000;
        string ans;
        while (i >= 1) {
            int divident = num / i;
            int remainder = num % i;
            if (i == 1000) {
                for (int j = 0; j < divident; j++) {
                    ans.push_back('M');
                }
            } else if (i == 100) {
                if (divident == 4) {
                    ans.push_back('C');
                    ans.push_back('D');
                } else if (divident == 9) {
                    ans.push_back('C');
                    ans.push_back('M');
                } else {
                    int number = divident * i;
                    if (number >= 500) {
                        number -= 500;
                        ans.push_back('D');
                    }
                    while (number >= 100) {
                        number -= 100;
                        ans.push_back('C');
                    }
                }

            } else if (i == 10) {
                if (divident == 4) {
                    ans.push_back('X');
                    ans.push_back('L');
                } else if (divident == 9) {
                    ans.push_back('X');
                    ans.push_back('C');
                } else {
                    int number = divident * i;
                    if (number >= 50) {
                        number -= 50;
                        ans.push_back('L');
                    }
                    while (number >= 10) {
                        number -= 10;
                        ans.push_back('X');
                    }
                }
            } else if (i == 1) {
                if (divident == 4) {
                    ans.push_back('I');
                    ans.push_back('V');
                } else if (divident == 9) {
                    ans.push_back('I');
                    ans.push_back('X');
                } else {
                    int number = divident * i;
                    if (number >= 5) {
                        number -= 5;
                        ans.push_back('V');
                    }
                    while (number >= 1) {
                        number -= 1;
                        ans.push_back('I');
                    }
                }
            }
            num = remainder;
            i = i / 10;
        }
        return ans;

        // 2nd approach
        // string s = "";
        // int v[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        // string symbol[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
        //                    "XL", "X",  "IX", "V",  "IV", "I"};

        // for (int i = 0; i < 13; i++) {
        //     while (num >= v[i]) {
        //         s += symbol[i];
        //         num -= v[i];
        //     }
        // }

        // return s;
    }
};