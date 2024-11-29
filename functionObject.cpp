#include <string>
#include <iostream>

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

int factorialTail(int n, int accumulator){
    if (n==0) return accumulator;
    return factorialTail(n-1, n*accumulator);
}   

//function Tower of Hanoi
void toh(int n, std::string from, std::string to, std::string temp){
    if (n==1){
        std::cout<<"move 1 disc from "<<from<<" to "<<to<<std::endl;
    } else {
        toh(n-1,from,temp,to);
        std::cout<<"move 1 disc from "<<from<<" to "<<to<<std::endl;
        toh(n-1,temp,to,from);
    }
}
int main(){
    int num;
    std::cin>>num;
    toh(num,"Primeira","do Meio","Ponta");
}