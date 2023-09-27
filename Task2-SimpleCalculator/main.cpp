/* Author:Rawan Khaled https://github.com/RawanKhaled20/Codsoft-cpp.git*/

#include <iostream>

using namespace std;

int main()
{
   double num1, num2, result;
   char operation;

    // Input two numbers
    cout << "Enter first number: "<<endl;
    cin >> num1;
    cout << "Enter second number: "<<endl;
    cin >> num2;

    // Input the operation (+, -, *, /)
    cout << "Choose an operation (+, -, *, /): "<<endl;
    cin >> operation;

    // Perform the selected operation
    switch (operation) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                cout << "Math Error! Division by zero is not allowed." << endl;
            }
            break;
        default:
            cout << "Invalid operation!" << endl;
               }

    // Display the result
    cout << "Result: " << num1 << " " << operation << " " << num2 << " = " << result << endl;
    return 0;
}
