#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void experiment1()
{
    ifstream file("test.txt");
    string data;

    if (!file)
    {
        cout << "File not found!";
        return;
    }

    while (file >> data)
    {
        bool num = true;

        for (int i = 0; i < data.length(); i++)
        {
            if (data[i] < '0' || data[i] > '9')
            {
                num = false;
                break;
            }
        }

        if (num)
            cout << data << " numeric constant" << endl;
        else
            cout << data << " not numeric" << endl;
    }

    file.close();
}

void experiment2()
{
    ifstream file("input.txt");
    string line;

    if (!file)
    {
        cout << "File not found!" << endl;
        return;
    }

    int count = 1;

    while (getline(file, line))
    {
        for (int i = 0; i < line.length(); i++)
        {
            if (line[i] == '+' || line[i] == '-' || line[i] == '*' || line[i] == '/' ||
                line[i] == '%' || line[i] == '=')
            {
                cout << "operator" << count << ": " << line[i] << endl;
                count++;
            }
        }
    }

    file.close();
}

void experiment3()
{
    ifstream file("inp.txt");
    string inp;

    if (!file)
    {
        cout << "File not found!" << endl;
        return;
    }

    while (getline(file, inp))
    {
        if (inp.length() >= 2 && inp[0] == '/' && inp[1] == '/')
        {
            cout << "This is a single line comment: " << inp << endl;
        }
        else if (inp.length() >= 4 && inp[0] == '/' && inp[1] == '*' &&
                 inp[inp.length() - 2] == '*' &&
                 inp[inp.length() - 1] == '/')
        {
            cout << "This is a multiple line comment: " << inp << endl;
        }
        else
        {
            cout << "This is not a comment: " << inp << endl;
        }
    }

    file.close();
}

void experiment4()
{
    ifstream file("inp.txt");
    string inp;

    if (!file)
    {
        cout << "File not found!" << endl;
        return;
    }

    while (file >> inp)
    {
        bool flag = false;

        if (inp[0] >= 'A' && inp[0] <= 'Z' || (inp[0] >= 'a' && inp[0] <= 'z') || inp[0] == '_')
        {
            for (char val : inp)
            {
                if ((val >= 'A' && val <= 'Z') ||
                    (val >= 'a' && val <= 'z') ||
                    val == '_' ||
                    (val >= '0' && val <= '9'))
                {
                    flag = true;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
        }
        else
        {
            flag = false;
        }

        if (flag)
            cout << inp << " --- Identifier" << endl;
        else
            cout << inp << " --- Not Identifier" << endl;
    }

    file.close();
}

void experiment5()
{

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];

    double average = (double)sum / n;

    cout << "Average = " << average << endl;

}
void experiment6()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int minVal = arr[0], maxVal = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < minVal)
            minVal = arr[i];
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    cout << "Minimum = " << minVal << endl;
    cout << "Maximum = " << maxVal << endl;
}
void experiment7()
{
    string firstName, lastName;

    cout << "Enter first name: ";
    cin >> firstName;
    cout << "Enter last name: ";
    cin >> lastName;

    string fullName = firstName + " " + lastName;

    cout << "Full name = " << fullName << endl;

}

int main()
{
    int n;

    cout << "Enter experiment number (1-7): ";
    cin >> n;

    switch (n)
    {
    case 1:
        experiment1();
        break;

    case 2:
        experiment2();
        break;

    case 3:
        experiment3();
        break;

    case 4:
        experiment4();
        break;
    case 5:
        experiment5();
        break;
    case 6:
        experiment6();
        break;
    case 7:
        experiment7();
        break;

    default:
        cout << "Invalid experiment number!" << endl;
    }

    return 0;
}
