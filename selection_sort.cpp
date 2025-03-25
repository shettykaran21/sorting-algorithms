#include <bits/stdc++.h>

using namespace std;

/*
    Select minimum and swap

    Time
    - Best case - O(n^2)
    - Average case - O(n^2)
    - Worst case - O(n^2)
*/
void selection_sort(vector<int> &v) {
    int n = v.size();

    for (int i = 0; i < n - 1; ++i) {
        int min_index = i;

        for (int j = i; j < n; ++j) {
            if (v[j] < v[min_index]) {
                min_index = j;
            }
        }

        swap(v[i], v[min_index]);
    }
}

void selection_sort_2(vector<int> &v) {
    int n = v.size();

    for (int i = 0; i < n - 1; ++i) {
        auto min_it = min_element(v.begin() + i, v.end());
        swap(v[i], *(min_it));
    }
}

int main() {
    vector<int> v = {10, 9, 7, 8, 1};

    selection_sort(v);

    for (int &el : v) {
        cout << el << ' ';
    }
    cout << '\n';

    return 0;
}