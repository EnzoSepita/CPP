//
// Created by enzo on 22/09/22.
//
#include<iostream>
#include<cmath>


int main(){
    int n;
    std::string prime = "True";


    while(std::cin >> n)
    {
        prime="True";
        if (n <= 1)
        {
            prime = "False";
            std::cout << n << " is a Prime : " << prime << '\n' ;
            continue;
        }
        for (int i = 2; i < sqrt(n); i++)
            if (n % i == 0) {
                prime = "False";
                break;
            }
        std::cout << n << " is a Prime : " << prime << '\n';

    }
    return 0;

}
