#include <iostream>
using namespace std;

int main()
{
    char op;
    float num1, num2;

    cout << "Start calculating!" << endl;

    cout << "Please enter the first number:" << endl;
    cin >> num1;
    cout << "Please enter the operator (either + or - or * or /):" << endl;
    cin >> op;
    cout << "Please enter the second number:" << endl;
    cin >> num2;

    switch(op)
    {
        case '+':
            cout << num1 << " + " << num2 << " = " << num1+num2 << endl;
            break;

        case '-':
            cout << num1 << " - " << num2 << " = " << num1-num2 << endl;
            break;

        case '*':
            cout << num1 << " * " << num2 << " = " << num1*num2 << endl;
            break;

        case '/':
            cout << num1 << " / " << num2 << " = " << num1/num2 << endl;
            break;

        default:
            // If the operator is other than +, -, * or /, error message is shown
            cout << "Error! operator is not correct" << endl;
            break;
    }

    return 0;

}
