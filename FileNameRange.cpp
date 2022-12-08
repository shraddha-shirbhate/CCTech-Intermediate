#include <iostream>
#include <string>
#include <algorithm>
#include <cassert>
#include <fstream>

using namespace std;

//Remove directories and select only file
string SplitFileName (const string& fileName){
  //cout << "Splitting: " << fileName << '\n';
  size_t found = fileName.find_last_of("/\\");
  //cout << " path: " << fileName.substr(0,found) << '\n';
  //cout << " file: " << fileName.substr(found+1) << '\n';
  return fileName.substr(found+1);
}

// remove extension from filename
string remExtn(const string& fileName) {  
    size_t lastindex = fileName.find_last_of("."); 
    string rawname = fileName.substr(0, lastindex); 
    return rawname;
}

// remove specified words
string remSpcifiedWords(string fileName)  
{
    string arr[] = {"tests","Tests","test","Test","spec","Spec","Step","step"}; 
    for(string rem : arr)
    {
        size_t index = fileName.find(rem,0);
        if(index != string::npos)
            fileName.erase(index,rem.length());
    }
    return fileName;
}

// remove Special characters
string remSpecialSymbols(string fileName) 
{
    char symbols[] = {'_','-','.'};
    for(char sym : symbols)
    {    
        fileName.erase(remove(fileName.begin(), fileName.end(),sym), fileName.end());
    }
    return fileName;
}

// get First and last index of desired file name
string getFirstAndLastIndex(const string& path, const string& fileName)    
{
    int arr[2];
    size_t first = path.find(fileName,0);
    arr[0]=first;
    arr[1]=first+fileName.length();
    return "[" + to_string(arr[0]) + "," + to_string(arr[1]) + "]";
}

// return the Index
string returnIndex(string fileName)   
{
    string rawfileName = SplitFileName(fileName);
    string noExtn = remExtn(rawfileName);
    string noSymbols = remSpecialSymbols(noExtn); 
    string noExtraWords = remSpcifiedWords(noSymbols);    
    return getFirstAndLastIndex(fileName,noExtraWords);
}

int main(int argc, char* argv[])
{    
    assert(returnIndex("src/Hiker_spec.re")=="[4,9]");
    assert(returnIndex("test/hiker_test.exs")=="[5,10]");
    assert(returnIndex("wibble/test/hiker_spec.rb")=="[12,17]");
    assert(returnIndex("hiker_step.rb")=="[0,5]");
    assert(returnIndex("hiker_spec.rb")=="[0,5]");
    assert(returnIndex("test_hiker.rb")=="[5,10]");
    assert(returnIndex("test_hiker.py")=="[5,10]");
    assert(returnIndex("test_hiker.sh")=="[5,10]");
    assert(returnIndex("tests_hiker.sh")=="[6,11]");
    assert(returnIndex("test_hiker.coffee")=="[5,10]");
    assert(returnIndex("hiker_spec.coffee")=="[0,5]");
    assert(returnIndex("hikerTest.chpl")=="[0,5]");
    assert(returnIndex("hiker.tests.c")=="[0,5]");
    assert(returnIndex("hiker_tests.c")=="[0,5]");
    assert(returnIndex("hiker_test.c")=="[0,5]");
    assert(returnIndex("hiker_Test.c")=="[0,5]");
    assert(returnIndex("HikerTests.cpp")=="[0,5]");
    assert(returnIndex("hikerTests.cpp")=="[0,5]");
    assert(returnIndex("HikerTest.cs")=="[0,5]");
    assert(returnIndex("HikerTest.java")=="[0,5]");
    assert(returnIndex("DiamondTest.kt")=="[0,7]");
    assert(returnIndex("HikerTest.php")=="[0,5]");
    assert(returnIndex("hikerTest.js")=="[0,5]");
    assert(returnIndex("hiker-test.js")=="[0,5]");
    assert(returnIndex("hiker-spec.js")=="[0,5]");
    assert(returnIndex("hiker.test.js")=="[0,5]");
    assert(returnIndex("hiker.tests.ts")=="[0,5]");
    assert(returnIndex("hiker_tests.erl")=="[0,5]");
    assert(returnIndex("hiker_test.clj")=="[0,5]");
    assert(returnIndex("fizzBuzz_test.d")=="[0,8]");
    assert(returnIndex("hiker_test.go")=="[0,5]");
    assert(returnIndex("hiker.tests.R")=="[0,5]");
    assert(returnIndex("hikertests.swift")=="[0,5]");
    assert(returnIndex("HikerSpec.groovy")=="[0,5]");
    assert(returnIndex("hikerSpec.feature")=="[0,5]");
    assert(returnIndex("hiker.feature")=="[0,5]");
    assert(returnIndex("hiker.fun")=="[0,5]");
    assert(returnIndex("hiker.t")=="[0,5]");
    assert(returnIndex("hiker.plt")=="[0,5]");
    assert(returnIndex("hiker")=="[0,5]");
    
    return EXIT_SUCCESS;
}