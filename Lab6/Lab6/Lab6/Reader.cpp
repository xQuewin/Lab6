#include "Reader.h"
#include <fstream>
#include <string>
#include <iostream>
#include <math.h>



using namespace std;

string numberString;
string binaryNumber;

Reader::Reader()
{
    decimalNumber = 0;
    badInput = false;
}



Reader::~Reader()
{
}



void Reader::ReadFile()
{
    ifstream inputFile("BinaryIn.dat");

    // Check if the file opened successfully
    if (!inputFile.is_open()) {
        cout << "Failed to open file!" << endl;
        return;
    }



    // Read each binary string from the file
    while (getline(inputFile, numberString)) {

        cout << "The Input Binary String Is : " << numberString << endl;

        badInput = false;
        int i = 0;
        decimalNumber = 0;
        int stringLength = numberString.length();

        if (BadInputCheck(numberString))
        {
            cout << "Bad Input Detected" << endl;
            cout << "--------------------------------------------" << endl;
        }
        else
        {
            GetBinaryForm(numberString);
            while (stringLength > 0)
            {

                int CurrentNumbInString = numberString[stringLength - 1];

                if (CurrentNumbInString == '1')
                {
                    decimalNumber = decimalNumber + pow(2, i);

                }

                stringLength--;
                i++;
            }

            cout << "The Decimal Version Of The Number Is : " << decimalNumber << endl;
            cout << "--------------------------------------------" << endl;
        }
    }

    inputFile.close();


}

void Reader::GetBinaryForm(const std::string& BinaryNumb)
{
    int i = 0;

    // Skip all leading underscores
    while ((i < BinaryNumb.size() && BinaryNumb[i] == '_') || (i < BinaryNumb.size() && BinaryNumb[i] == ' ')) {
        i++;
    }
    // Print the remaining characters
    cout << "The Binary Form Of The Number Is : ";
    for (; i < BinaryNumb.size(); i++)
    {
        cout << BinaryNumb[i];
    }
    cout << endl;
}



bool Reader::BadInputCheck(const std::string& str)
{
    int i = 0;

    // Skip all leading underscores
    while ((i < str.size() && str[i] == '_') || (i < str.size() && str[i] == ' ')) {
        i++;
    }

    // Check the remaining characters
    for (; i < str.size(); i++) {
        if (str[i] != '0' && str[i] != '1') {
            return true;  // Found an invalid character
        }
    }
    return false;  // Only valid characters found
}