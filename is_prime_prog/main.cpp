//
// Created by enzo on 22/09/22.
//
#include<iostream>
#include<cmath>


int main(){
    long long n;


    while(std::cin >> n)
    {
        bool prime= true;
        if (n <= 1)
        {
            prime = false;
        }
        for (long long i = 2; i <= std::sqrt(n); i++) {
            if (n % i == 0) {
                prime = false;
                break;
            }
        }
        if (prime)
            std::cout << n << " is a Prime: True\n";
        else
            std::cout << n << " is a Prime: False\n";

    }
    return 0;

}

