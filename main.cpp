#include <iostream>
#include <iomanip> // For formatting a double-precision number.
#include <string>

// Add this line to avoid repeating ::std
using namespace std;

// Prototype for the extractNumeric function
double extractNumeric(const string& str);

int main () {
    string input;
    
    while (true) { 
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") {
            break;
        }
    
        double number = extractNumeric(input);
    
        if (number != -999999.99) {
            cout << "The input is: " << fixed << setprecision(4)
                << number << endl;
        }  
        else {
            cout << "The input is invalid." << endl;
        }
    }
    
    return 0;
}

double extractNumeric(const string& str) {
    
    int decimalCount = 0; //keeps track of number of '.' in str

    //iterate through the string
    for (int i = 0; i < str.length(); i++) {

        //you can only have one + or - at the beginning
        if ((str[i] == '-' || str[i] == '+') && i != 0) {
            return -999999.99;
        }

        //allows for decimal points
        if (str[i] == '.' && decimalCount == 0) {
            decimalCount++;
        }
        //you can only have one decimal point
        else if (str[i] == '.') {
            return -999999.99;
        }

        //checks for digits ONLY (excluding '.', '+', and '-')
        if ((str[i] < '0' || str[i] > '9') && str[i] != '.' && str[i] != '+' && str[i] != '-') {
            return -999999.99;
        }
    }

    //convert the string to a double
    return stod(str);
}

