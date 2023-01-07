#include <bits/stdc++.h>

using namespace std;

int evalRPN(vector<string>& tokens) {
    int index = 0;

    while (tokens.size() > 1) {
        if (tokens[index].size() == 1) {
            if (tokens[index][0] == '+') {
                tokens[index - 2] = to_string(stoi(tokens[index - 2]) + stoi(tokens[index - 1]));
                // remove id i - 1 and i
                tokens.erase(tokens.begin()+index-1, tokens.begin()+index+1);
                index -= 2;
            } else if (tokens[index][0] == '-') {
                tokens[index - 2] = to_string(stoi(tokens[index - 2]) - stoi(tokens[index - 1]));
                // remove id i - 1 and i
                tokens.erase(tokens.begin()+index-1, tokens.begin()+index+1);
                index -= 2;
            } else if (tokens[index][0] == '*') {
                tokens[index - 2] = to_string(stoi(tokens[index - 2]) * stoi(tokens[index - 1]));
                // remove id i - 1 and i
                tokens.erase(tokens.begin()+index-1, tokens.begin()+index+1);
                index -= 2;
            } else if (tokens[index][0] == '/') {
                tokens[index - 2] = to_string(stoi(tokens[index - 2]) / stoi(tokens[index - 1]));
                // remove id i - 1 and i
                tokens.erase(tokens.begin()+index-1, tokens.begin()+index+1); 
                index -= 2;  
            }
        }

        index++;
    }

    return stoi(tokens[0]);
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

