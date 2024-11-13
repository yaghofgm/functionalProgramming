
#include <string>

int factorial(int n){
    if(n==0) return 1;
    return n*factorial(n-1);
}

int power(int b, int p){
    if (p==0) return 1;
    return b*power(b, p-1);
}

//function that checks whether a string is a palyndorome
bool isPalindrome(const std::string& s){
    if (s.size()<2) return true;
    if (s[0] != s[s.size()-1]) return false;
    return isPalindrome(s.substr(1, s.size()-2));
}