#include <bits/stdc++.h>

using namespace std;

/*
    Move largest element to last by adjacent swaps

    Time
    - Best case - O(n) (Best case is when array is already sorted)
    - Average case - O(n^2)
    - Worst case - O(n^2)
*/
void bubble_sort(vector<int> &v) {
    int n = v.size();
    bool swapped = false;

    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (v[j + 1] < v[j]) {
                swap(v[j], v[j + 1]);
                swapped = true;
            }
        }

        if (!swapped) return;
    }
}

int main() {
    vector<int> v = {10, 9, 7, 8, 1};

    bubble_sort(v);

    for (int &el : v) {
        cout << el << ' ';
    }
    cout << '\n';

    return 0;
}