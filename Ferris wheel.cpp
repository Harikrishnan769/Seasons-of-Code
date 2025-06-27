#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main() {
    int n, max_weight;
    cin >> n >> max_weight;

    vector<int> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());

    int i = 0, j = n - 1;
    int c = 0;

    while (i <= j) {
        if (i == j) {
            c++; // one person left
            break;
        }

        if (weights[i] + weights[j] <= max_weight) {
            i++;
            j--;
        } else {
            j--;
        }
        c++;
    }

    cout << c;
}
