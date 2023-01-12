#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <cassert>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

class CurrencyConverterIO
{
public:
    CurrencyConverterIO(string);
    int chooseCurrency();
    double convertCurrency(string, string, double);
    vector<string> currencyList;
    string inputCurrency, outputCurrency;

private:
    void showCurrencyOptions();
    map<string, double> currency;
};

CurrencyConverterIO::CurrencyConverterIO(string filename)
{
    ifstream ifs(filename, ios::in);
    if (ifs.good())
    {
        string line;
        string curr;
        double factor;
        set<string> currencySet;
        while (getline(ifs, line))
        {
            stringstream ss;
            ss << line;
            ss >> curr;
            ss >> factor;
            currencySet.insert(curr.substr(0, 3));
            currency[curr] = factor;
        }
        for (auto currency : currencySet)
            currencyList.push_back(currency);
    }
}

int CurrencyConverterIO::chooseCurrency()
{
    CurrencyConverterIO::showCurrencyOptions();
    int option;
selectCurrency:
    cout << ">";
    cin >> option;
    if (cin.fail())
        cout << "Please enter a valid number" << std::endl;
    if ((option < 0) || (option > (currencyList.size())))
    {
        cout << "The number is out of range" << std::endl;
        cout << "Select the input/output currency from the list" << std::endl;
        goto selectCurrency;
    }
    return --option;
}

double CurrencyConverterIO::convertCurrency(string inputCurrency, string outputCurrency, double amount)
{
    string key = inputCurrency + "=>" + outputCurrency;
    double conversion = 0;
    for (int idx = 0; idx < currency.size(); idx++)
    {
        if (currency.find(key) != currency.end())
        {
            conversion = currency[key];
            conversion *= (double)amount;
        }
    }
    return conversion;
}

void CurrencyConverterIO::showCurrencyOptions()
{
    for (int i = 0; i < currencyList.size(); i++)
    {
        std::cout << i + 1 << ". " << currencyList[i] << std::endl;
    }
}

void driverFunction(){
    char continueOption;
    do
    {
        string inputCurrency, outputCurrency;
        double inputAmount;
        CurrencyConverterIO cc("conversion.txt");

        cout << "****************************************" << endl;
        cout << "  Welcome to CCTech Currency converter  " << endl;
        cout << "****************************************" << endl;
        
        cout << "Select the input currency from the list" << std::endl;
        int option = cc.chooseCurrency();
        inputCurrency = cc.currencyList[option];
        auto it = find(cc.currencyList.begin(), cc.currencyList.end(), cc.currencyList[option]);
        cc.currencyList.erase(it);

        cout << endl;
        cout << "Select the output currency from the list" << std::endl;
        option = cc.chooseCurrency();
        outputCurrency = cc.currencyList[option];

        cout << std::endl;
        cout << "Please enter the amount" << endl;
        cout << ">";
        cin >> inputAmount;

        cout << endl;
        double outputAmount = cc.convertCurrency(inputCurrency, outputCurrency, inputAmount);
        cout << inputAmount << " " << inputCurrency << " would be " << outputAmount << " " << outputCurrency << " on 2023-01-06" << endl;
        cout << "Do you wish to continue with another conversion (Y/N)" << endl;
        cin >> continueOption;
    } while (continueOption == 'Y' || continueOption == 'y');
}

int main(){

    driverFunction();
    CurrencyConverterIO io("conversion.txt");
  
    assert(io.currencyList == (vector<string>{"AUD","CHF","CNY","EUR","GBP","INR","JPY","SGD","USD"}));
   
    assert(io.convertCurrency("AUD","INR",5)==284.8);
    assert(io.convertCurrency("INR","USD",10)==0.121);
    assert(round(io.convertCurrency("USD","INR",0.121))==10);
    assert(round(io.convertCurrency("GBP","USD",5))==5);
    return 0;
}