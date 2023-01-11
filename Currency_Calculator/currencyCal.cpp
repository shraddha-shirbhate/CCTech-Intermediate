#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include <set>
#include <vector>

using namespace std;

class currencyConverter
{
private:
    unsigned int inputCurrencyType;
    unsigned int outputCurrencyType;
    double conversionRate;
    double amount;
    double referenceToUSD;

public:
    currencyConverter() : conversionRate(0){};
    void printInputCurrencyList();
    void selectInputCurrency();
    void printOutputCurrenciesList();
    void selectOutputCurrency();
    void readCurrencyRatesFromFile();
    void enterAmount();
    void convertToUSDReference();
    void finalCurrencyConversion();
    void runAllFunctions();
};

vector<string> currenciesTypes = {"USD", "GBP", "INR", "EUR", "CHF", "AUD", "SGD", "CNY", "JPY"};
void currencyConverter::printInputCurrencyList()
{
    cout << "Welcome to CCTech Currency converter:" << endl;
    cout << "Following are the output currencies" << endl;

    for (int i = 0; i < currenciesTypes.size(); ++i)
    {
        cout << i + 1 << "." << currenciesTypes[i] << endl;
    }
}

void currencyConverter::selectInputCurrency()
{
    cout << "\nSelect the input currency from the list" << endl;
    cout << ">";
    cin >> inputCurrencyType;

    if (!inputCurrencyType <= currenciesTypes.size())
        cout << "You have selected : " << currenciesTypes[inputCurrencyType - 1] << " currency" << endl;
    else
        cerr << "Warning: Invalid Input " << endl;
}

void currencyConverter::printOutputCurrenciesList()
{
    vector<string>::iterator itr;

    itr = find(currenciesTypes.begin(), currenciesTypes.end(), currenciesTypes[inputCurrencyType - 1]);
    currenciesTypes.erase(itr);

    cout << "\nFollowing are the output currencies:" << endl;
    for (int i = 0; i < currenciesTypes.size(); ++i)
    {
        cout << i + 1 << "." << currenciesTypes[i] << endl;
    }
}

void currencyConverter::selectOutputCurrency()
{
    cout << "\nSelect the output currency from the list" << endl;
    cout << ">";
    cin >> outputCurrencyType;

    if (outputCurrencyType <= currenciesTypes.size())
        cout << "You have selected output currency : " << currenciesTypes[outputCurrencyType - 1] << " currency" << endl;

    else
        cerr << "Warning: Invalid Input. Please try again!! " << endl;
}

void currencyConverter::readCurrencyRatesFromFile()
{
    ifstream file("conversion_rates.txt", ios::in);
    string show_text;
    auto search = currenciesTypes[outputCurrencyType - 1];

    if (file.is_open())
    {
        string convertIntoInt;
        stringstream ss;

        while (getline(file, show_text))
        {
            if (show_text.find_last_of(search) != string::npos)
            {
                for (int i = 4; i < 12; ++i)
                {
                    show_text.erase(remove(show_text.begin(), show_text.end(), '.'), show_text.end());
                    convertIntoInt += show_text[i];
                }
            }
        }
        ss << convertIntoInt;
        ss >> conversionRate;
    }
    else
        cerr << "Could not open file conversion_rates.txt" << endl;

    file.close();
}

void currencyConverter::enterAmount()
{
    cout << "\nEnter the amount you want to convert : ";
    cin >> amount;
}

void currencyConverter::convertToUSDReference()
{
    switch (inputCurrencyType)
    {
    case 1:
        referenceToUSD = amount * 1;
        break;
    case 2:
        referenceToUSD = amount * 1.2165692;
        break;
    case 3:
        referenceToUSD = amount * 0.012143487;
        break;
    case 4:
        referenceToUSD = amount * 1.0678432;
        break;
    case 5:
        referenceToUSD = amount * 1.0818219;
        break;
    case 6:
        referenceToUSD = amount * 0.69282967;
        break;
    case 7:
        referenceToUSD = amount * 0.75029716;
        break;
    case 8:
        referenceToUSD = amount * 0.14743201;
        break;
    case 9:
        referenceToUSD = amount * 0.0075577008;
        break;
    default:
        cerr << "Nothing is selected " << endl;
        break;
    }
}

void currencyConverter::finalCurrencyConversion()
{
    if (outputCurrencyType == 2)
    {
        double convertedAmount = (conversionRate / 100000) * referenceToUSD;
        cout << "\nConverted Amount 1: " << convertedAmount << " " << currenciesTypes[outputCurrencyType - 1] << endl;
    }
    else if (outputCurrencyType == 8)
    {
        double convertedAmount = (conversionRate / 10000) * referenceToUSD;
        cout << "\nConverted Amount 2: " << convertedAmount << " " << currenciesTypes[outputCurrencyType - 1] << endl;
    }
    else
    {
        double convertedAmount = (conversionRate / 1000000) * referenceToUSD;
        cout << "\nConverted Amount 3: " << convertedAmount << " " << currenciesTypes[outputCurrencyType - 1] << endl;
    }
}

void currencyConverter::runAllFunctions()
{
    printInputCurrencyList();
    selectInputCurrency();
    printOutputCurrenciesList();
    selectOutputCurrency();
    readCurrencyRatesFromFile();
    enterAmount();
    convertToUSDReference();
    finalCurrencyConversion();
}

int main()
{
    currencyConverter cc;
    cc.runAllFunctions();

    char c;
    cout << "Do you want to continue (Press y/Y for Yes and n/N for No): ";
    cin >> c;

    if (c == 'Y' || c == 'y')
    {
        cc.runAllFunctions();
    }
    else
        cout << "Thanks You!! " << endl;

    return 0;
}