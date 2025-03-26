#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &v, int low, int high) {
    int pivot = v[low];

    int i = low, j = high;

    while (i < j) {
        while (v[i] <= pivot && i <= high) {
            i++;
        }
        while (v[j] > pivot && j >= low) {
            j--;
        }

        if (i < j) {
            swap(v[i], v[j]);
        }
    }

    swap(v[low], v[j]);

    return j;
}

/*
    Time

    Time - O(nlogn)
    Space - O(1)
*/
void quick_sort(vector<int> &v, int low, int high) {
    if (low < high) {
        int pi = partition(v, low, high);

        quick_sort(v, low, pi - 1);
        quick_sort(v, pi + 1, high);
    }
}

void solve(vector<int> &v) {
    int low = 0, high = v.size() - 1;
    quick_sort(v, low, high);
}

int main() {
    vector<int> v = {10, 9, 7, 8, 1};

    solve(v);

    for (int &el : v) {
        cout << el << ' ';
    }
    cout << '\n';

    return 0;
}