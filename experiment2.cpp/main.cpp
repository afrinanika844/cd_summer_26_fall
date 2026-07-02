#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

bool isKeyword(char buffer[])
{
    char keywords[32][10] = {
        "auto","break","case","char","const","continue","default",
        "do","double","else","enum","extern","float","for","goto",
        "if","int","long","register","return","short","signed",
        "sizeof","static","struct","switch","typedef","union",
        "unsigned","void","volatile","while"
    };

    for (int i = 0; i < 32; i++)
    {
        if (strcmp(keywords[i], buffer) == 0)
            return true;
    }
    return false;
}

bool isIdentifier(string s)
{
    if (!((s[0] >= 'A' && s[0] <= 'Z') ||
          (s[0] >= 'a' && s[0] <= 'z') ||
           s[0] == '_'))
        return false;

    for (char c : s)
    {
        if (!((c >= 'A' && c <= 'Z') ||
              (c >= 'a' && c <= 'z') ||
              (c >= '0' && c <= '9') ||
               c == '_'))
            return false;
    }
    return true;
}

bool isNumber(string s)
{
    bool dot = false;

    for (char c : s)
    {
        if (c == '.')
        {
            if (dot) return false;
            dot = true;
        }
        else if (!isdigit(c))
            return false;
    }
    return true;
}

int main()
{
    string input = "cout << a + b % 60 * 2.75;";

    char buffer[50];
    int j = 0;

    string operators = "+-*/%=<>";

    for (int i = 0; i < input.length(); i++)
    {
        char ch = input[i];

        // operator check
        if (operators.find(ch) != string::npos)
        {
            cout << ch << " is operator\n";
        }

        // build token
        if (isalnum(ch) || ch == '.')
        {
            buffer[j++] = ch;
        }
        else if ((ch == ' ' || ch == ';' || ch == '\n' || ch == '<') && j != 0)
        {
            buffer[j] = '\0';
            j = 0;

            string token(buffer);

            if (isKeyword(buffer))
                cout << token << " is keyword\n";
            else if (isNumber(token))
                cout << token << " is number\n";
            else if (isIdentifier(token))
                cout << token << " is identifier\n";
            else
                cout << token << " is not identifier\n";
        }
    }

    return 0;
}
