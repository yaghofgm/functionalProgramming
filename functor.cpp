#include <list>
#include <math.h>
#include <iostream>

using namespace std;

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
        if (j%i == 0) return false;
    }
    return true;
}

bool any_odd(list<int> l){
    for (list<int>::iterator i = l.begin(); i!= l.end(); i++){
        // if (*i % 2 == 1) return true;
        if (is_odd(*i)) return true;
    }
    return false;
}
bool any_even(list<int> l){
    for (auto i:l){
        if(is_even(i)) return true;
    }
    return false;
}
bool any_prime(list<int> l){
    for (auto i:l){
        if(is_prime(i)) return true;
    }
    return false;
}

//now let us make a function any_of that can do the work of all the others.
//We can use functional programming for this.
//we will have the function pointer as an argument 
//this is better, more compartimentizing, since any function is_something works as argument 
template <typename T> //so that it can take in the class as a function
bool any_of(list<int> l, T predicate){
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
    
    bool operator() (int n){ //overloads the () operator
        return n>limit;
    }
    //when we call on main,looks like a function! 
};

int main(){
    // GreaterN g2(2);
    // GreaterN g6(6);
    // cout<<g2(4)<<endl; //true 
    // cout<<g6(4)<<endl; //true
    
    list<int> l ={1,2,3};
    int limit;
    cin>>limit;
    GreaterN gn(limit);
    // cout<<gn(4)<<endl;
    cout<<any_of(l,gn)<<endl; //is any element bigger than the limit
}


