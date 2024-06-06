#include <iostream>
using namespace std;

// Function to calculate power using recursion
int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    } else {
        return base * power(base, exponent - 1);
    }
}

int main() {
    int a ;
    int b ;
    cin>>a;
    cin>>b;
    int result = power(a, b);
    cout << a << " raised to the power of " << b << " is: " << result << endl;
    return 0;
}
