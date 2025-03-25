#include <bits/stdc++.h>

using namespace std;

void merge(vector<int> &v, int low, int mid, int high) {
    int n1 = mid - low + 1;
    int n2 = high - mid;

    vector<int> l(n1), r(n2);

    // Copy elements to the temp vectors
    for (int i = 0; i < n1; ++i) {
        l[i] = v[low + i];
    }
    for (int j = 0; j < n2; ++j) {
        r[j] = v[mid + 1 + j];
    }

    int i = 0, j = 0, k = low;

    // Merge temp vectors back to v
    while (i < n1 && j < n2) {
        if (l[i] <= r[j]) {
            v[k] = l[i];
            i++;
        } else {
            v[k] = r[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements
    while (i < n1) {
        v[k] = l[i];
        k++;
        i++;
    }

    while (j < n2) {
        v[k] = r[j];
        k++;
        j++;
    }
}

void merge_sort(vector<int> &v, int low, int high) {
    if (low >= high) {
        return;
    }

    int mid = low + (high - low) / 2;

    merge_sort(v, low, mid);
    merge_sort(v, mid + 1, high);

    merge(v, low, mid, high);
}

void solve(vector<int> &v) {
    merge_sort(v, 0, v.size() - 1);
}

int main() {
    vector<int> v = {3, 1, 2, 4, 1, 5, 2, 6, 4};

    solve(v);

    for (int &el : v) {
        cout << el << ' ';
    }
    cout << '\n';

    return 0;
}