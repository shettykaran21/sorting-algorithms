#include <bits/stdc++.h>

using namespace std;

/*
    Take an element and place it in it's correct order.
    Analogy: Sorting Playing cards. We divide the cards into two groups: sorted and unsorted. Pick a card from the unsorted part and place it in it's correct position.

    Time
    - Best case - O(n) (When array is already sorted)
    - Average case - O(n^2) (If the list is randomly ordered)
    - Worst case - O(n^2) (If the list is in reverse order)
*/
void insertion_sort(vector<int> &v) {
    int n = v.size();

    for (int i = 1; i < n; ++i) {
        int key = v[i];
        int j = i - 1;

        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }
}

int main() {
    vector<int> v = {10, 9, 7, 8, 1};

    insertion_sort(v);

    for (int &el : v) {
        cout << el << ' ';
    }
    cout << '\n';

    return 0;
}