#include <iostream>
using namespace std;


int recursiveSum(int arr[], int n) {
    if (n == 0)
        return 0;
    return arr[n - 1] + recursiveSum(arr, n - 1);
}


int iterativeSum(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}

int main() {
    int n;
    cout << "Enter size: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Recursive Sum = " << recursiveSum(arr, n) << endl;
    cout << "Iterative Sum = " << iterativeSum(arr, n) << endl;

    return 0;
}