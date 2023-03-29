#include <bits/stdc++.h>

using namespace std;

int resolve(int number1, int number2, string operation) {
    if (operation == "+") return number1 + number2;
    else if (operation == "-") return number1 - number2;
    else if (operation == "*") return number1 * number2;
    else return number1 / number2;
}


int evalRPN(vector<string> &tokens) {
    stack<int> results;

    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
            int number2 = results.top();
            results.pop();
            int number1 = results.top();
            results.pop();
            results.push(resolve(number1, number2, tokens[i]));
        } else {
            results.push(stoi(tokens[i]));
        }
    }

    return results.top();
}

int main(int argc, char const *argv[])
{

    int totalTokens;
    cin >> totalTokens;
    vector<string> tokens(totalTokens);

    for (int index = 0; index < totalTokens; index++) {
        cin >> tokens[index];
    }
    
    cout << evalRPN(tokens) << endl;

    return 0;
}

