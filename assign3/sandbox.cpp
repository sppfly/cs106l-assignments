/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */
#include "class.h" 
#include <print>
 

void sandbox() {
    // STUDENT TODO: Construct an instance of your class!
    myvector<int> vec(10); 
    for (int i = 0; i < 10; i++) {
        vec.add(i);
    }
    for (int i = 0; i < 10; i++) {
        std::println("{}", vec[i]);
    }
    
    myvector<int> copyc = vec; 
}