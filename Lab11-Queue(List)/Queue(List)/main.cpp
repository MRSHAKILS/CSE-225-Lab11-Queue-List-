#include <iostream>

using namespace std;

int main() {
    int n;
    cout << "Enter number of coin types: ";
    cin >> n;

    int coins[100]; // Assuming maximum 100 coin types
    cout << "Enter coin values: ";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int amount;
    cout << "Enter amount: ";
    cin >> amount;

    // Sort coins for the greedy approach using basic bubble sort
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (coins[j] > coins[j+1]) {
                int temp = coins[j];
                coins[j] = coins[j+1];
                coins[j+1] = temp;
            }
        }
    }

    int count = 0;
    int remainingAmount = amount;

    for (int i = n - 1; i >= 0; i--) {
        while (remainingAmount >= coins[i]) {
            remainingAmount -= coins[i];
            count++;
        }
    }

    cout << "Minimum coins required: " << count << endl;

    return 0;
}
