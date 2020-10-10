// C++ Program to find LCM of two
// prime numbers
//gcd of two prime numbers is 1 therefore lcm=a*b
#include <bits/stdc++.h>
using namespace std;

// Function to return the LCM of two
// prime numbers
int findLCMPrime(int a, int b)
{
    // If the two numbers are equal
    // then return any one of a and b
    if (a == b) {
        return a;
    }

    // Else return product of numbers
    return a * b;
}

// Driver code
int main()
{
    // Given two numbers
    int a = 3, b = 5;

    // Function Call
    cout << findLCMPrime(a, b);
    return 0;
}
