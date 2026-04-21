#include <iostream>
using namespace std;

long long digitSum(string n) {
    long long sum = 0;
    for (int i = 0; i < n.length(); i++) {
        sum += n[i] - '0';
    }
    return sum;
}

int superDigit(long long n) {
    if (n < 10)
        return n;
    
    long long sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    
    return superDigit(sum);
}

int main() {
    string n;
    int k;

    cout << "Enter number: ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;

    long long initialSum = digitSum(n) * k;

    cout << "Super Digit: " << superDigit(initialSum);

    return 0;
}