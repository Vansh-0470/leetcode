class Solution {
public:
    bool isnumber(char s) {
        return s >= '0' && s <= '9';
    }

    int calculate(string s) {

        stack<char> operation;
        stack<int> number;

        bool expectnumber = true;

        for (int i = 0; i < s.length(); i++) {

            // Ignore spaces
            if (s[i] == ' ')
                continue;


            else if (s[i] == '+' || s[i] == '-') {

                // Binary operator
                if (!expectnumber) {

                    operation.push(s[i]);
                    expectnumber = true;
                }

                // Unary operator
                else {

                    int sign = (s[i] == '-') ? -1 : 1;

                    i++;

                    // Skip spaces
                    while (i < s.length() && s[i] == ' ')
                        i++;

                    // Unary sign before '('
                    if (i < s.length() && s[i] == '(') {

                       // just add 0 in number and - in operator 
                        if (sign == -1) {
                            number.push(0);
                            operation.push('-');
                        }

                        operation.push('(');

                        expectnumber = true;

                        continue;
                    }

                    // Unary sign before number
                    string help;

                    while (i < s.length() && isnumber(s[i])) {
                        help.push_back(s[i]);
                        i++;
                    }

                    i--;

                    long long x = stoll(help);

                    number.push(sign * x);

                    expectnumber = false;
                }
            }


            
            else if (s[i] == '(') {

                operation.push('(');

                expectnumber = true;
            }


         
            else if (s[i] == ')') {

                // Solve everything inside ()
                while (operation.top() != '(') {

                    int b = number.top();
                    number.pop();

                    int a = number.top();
                    number.pop();

                    if (operation.top() == '+')
                        number.push(a + b);
                    else
                        number.push(a - b);

                    operation.pop();
                }

                // Remove '('
                operation.pop();

                expectnumber = false;


                
                // IMPORTANT:
                // taken help from gpt 
                // Bracket is now one complete number.
                // Apply the pending operation outside it.
               
                if (!operation.empty() && operation.top() != '(') {

                    int b = number.top();
                    number.pop();

                    int a = number.top();
                    number.pop();

                    if (operation.top() == '+')
                        number.push(a + b);
                    else
                        number.push(a - b);

                    operation.pop();
                }
            }


            else {

                string help;

                while (i < s.length() && isnumber(s[i])) {
                    help.push_back(s[i]);
                    i++;
                }

                i--;

                long long  x = stoll(help);

                // If an operator is waiting,
                // calculate immediately.
                if (!operation.empty() && operation.top() != '(') {

                    int b = x;
                    int a = number.top();

                    number.pop();

                    if (operation.top() == '+')
                        number.push(a + b);
                    else
                        number.push(a - b);

                    operation.pop();
                }

                else {
                    number.push(x);
                }

                expectnumber = false;
            }
        }


       
        while (!operation.empty()) {

            int b = number.top();
            number.pop();

            int a = number.top();
            number.pop();

            if (operation.top() == '+')
                number.push(a + b);
            else
                number.push(a - b);

            operation.pop();
        }

        return number.top();
    }
};