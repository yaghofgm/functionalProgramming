#include <list>
#include <math.h>
#include <iostream>

using namespace std;

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
bool any_of(list<int> l, bool (*predicate)(int)){
    for (auto i:l){
        if (predicate(i)) return true;
    }
    return false;
}

int main(){
    list<int> list = {3,5,7};
    bool (*name)(int); 
    name = &is_odd; //& is optional
    cout<<(*name)(42)<<endl; //optional too
    cout<< name(42)<<endl; 
    cout<<is_odd<<endl;
    cout<<name<<endl;

    cout<<endl;

    name = &is_odd;
    cout<<any_of(list,name)<<endl;
    cout<<any_of(list, &is_odd)<<endl; //any_odd tdoes not work since takes list, not int
    cout<<any_of(list,is_even)<<endl; 
    cout<<any_of(list,is_prime)<<endl; //can ommit the & too
}