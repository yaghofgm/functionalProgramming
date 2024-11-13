#include <list>
#include <cmath>
#include <iostream>

using std::list;
using std::sqrt;
using std::cout;
using std::cin;
using std::endl;

#pragma region Functions
bool is_odd (int i){
    return (i % 2 == 1);
}
bool is_even (int i){
    return (i % 2 == 0);
}
bool is_prime (int i){
    // for (int j=2; j< i; j++){
    //     if (j%i == 0) return false;
    // }
    // return true;

    //can make it better, just sqrt i, 
    for (int j=2; j<int(sqrt(i)); j++){
        if (i % j == 0) return false;
    }
    return true;
}

bool any_odd(const list<int>& l){
    for (list<int>::const_iterator i = l.begin(); i!= l.end(); i++){
        // if (*i % 2 == 1) return true;
        if (is_odd(*i)) return true;
    }
    return false;
}
bool any_even(const list<int>& l){
    for (const auto& i : l){
        if(is_even(i)) return true;
    }
    return false;
}
bool any_prime(const list<int>& l){
    for (const auto& i : l){
        if(is_prime(i)) return true;
    }
    return false;
}

//now let us make a function any_of that can do the work of all the others.
//We can use functional programming for this.
//we will have the function pointer as an argument 
//this is better, more compartimentizing, since any function is_something works as argument 
template <typename T> //so that it can take in the class as a function
bool any_of(const list<int>& l, T predicate){
    for (auto i:l){
        if (predicate(i)) return true;
    }
    return false;
}

#pragma endregion

class GreaterN{
    int limit;
public: 
    GreaterN(int limit_in) : limit(limit_in){}
    
    bool operator() (int n) const { //overloads the () operator
        return n>limit;
    }
    //when we call on main,looks like a function! 
};

class Animal{
    std::string name;
public: 
    Animal(const std::string& name_in) : name(name_in){}
    std::string getName() const {return name;}
};

class AnimalLess{
public:
    bool operator()(const Animal& A, const Animal& B) const{
        return A.getName() < B.getName();
    }
};

int main(){
    // GreaterN g2(2);
    // GreaterN g6(6);
    // cout<<g2(4)<<endl; //true 
    // cout<<g6(4)<<endl; //true
    
    /*
    list<int> l ={1,2,3};
    int limit;
    if (!(cin >> limit)) {
        cout << "Invalid input. Please enter an integer." << endl;
        return 1;
    }
    GreaterN gn(limit);
    // cout<<gn(4)<<endl;
    cout<<any_of(l,gn)<<endl; //is any element bigger than the limit
    */

   AnimalLess less;
   Animal arara("arara");
   Animal piau("piau");
   cout<<less(arara,piau)<<endl;
}


