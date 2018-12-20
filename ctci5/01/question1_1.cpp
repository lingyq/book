#include<iostream>
#include<string>
#include "question1_1.h"
using namespace std;

bool question1_1::isUniqueChars(const string& str) {
    if(str.length() > 256) {
        return false;
    }
    unsigned int checker = 0;
    for(int i = 0; i < str.length(); ++i) {
        int value = str[i] - 'a';
        if((checker & (1 << value)) != 0)
            return false;
        checker |= (1 << value);
    }
    return true;
}

bool question1_1::isUniqueChars2(const string& str) {
    if(str.length() > 256) {
        return false;
    }
    bool ascii_set[256] = {false};
    for(int i = 0; i < str.length(); ++i) {
        int value = str[i];
        if(ascii_set[value]) {
            return false;
        }
        ascii_set[value] = true;    
    }
    return true;
}

/* Function to print true and false */
string question1_1::result(bool value) {
    if(value) {
        return "True";
    }
    return "False";
}

int question1_1::run() {
    string input[] ={"abcde", "aba"};
    for(int i = 0; i < 2; i++) {
        cout << input[i] << " has unique characters: " << result(isUniqueChars(input[i])) << endl;
        cout << input[i] << " has unique characters: " << result(isUniqueChars2(input[i])) << endl;
    }
    return 0;
}
int main(){
	question1_1().run();
}