#include <iostream>

using namespace std;

bool check_number(string str) 
{
    int dot = 1;
    int polarity = 1;

    for (int i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]) == false)
        {
            if (str[i] == ' ')
            {
                continue;
            }
            else if (str[i] == '.' && dot == 1)
            {
                dot--;
                polarity--;
                continue;
            }
            else if (str[i] == '+' && polarity == 1 || str[i] == '-' && polarity == 1)
            {
                polarity--;
                continue;
            }
            else
            {            
                return false;
                break;
            }
        }
        else
        {
            if (i == (str.length() -1))
            {
                return true;
                break;
            }
            else
            {
                continue;
            }
        }
    }
    
    return 0;
}

int main() 
{
    string x;

    cout << "Pls give a number: ";

    cin >> x; 

    cout << check_number(x);

}