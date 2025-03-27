#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &v, int low, int high) {
    int pivot = v[low];

    int i = low, j = high;

    while (i < j) {
        // Move i till it's <= pivot. i.e. after this, i will be pointing to the el > pivot
        while (i <= high && v[i] <= pivot) {
            i++;
        }

        // Move j till it's > pivot. i.e. after this, j will be pointing to the el <= pivot
        while (j >= low && v[j] > pivot) {
            j--;
        }

        if (i < j) {
            swap(v[i], v[j]);
        }
    }

    // Place pivot element to its correct place
    swap(v[low], v[j]);

    return j;
}

// Pick random element and swap it with first element
// In case of choosing first element as pivot, worst case is when array is in descending order.
// In case of choosing last element as pivot, worst case is when array is in ascending order (already sorted).
int partition_r(vector<int> &v, int low, int high) {
    srand(time(NULL));
    int random = low + rand() % (high - low);

    swap(v[random], v[low]);

    return partition(v, low, high);
}

/*
    Time

    Time - O(nlogn)
    Space - O(1)
*/
void quick_sort(vector<int> &v, int low, int high) {
    if (low < high) {
        int pi = partition_r(v, low, high);

        quick_sort(v, low, pi - 1);
        quick_sort(v, pi + 1, high);
    }
}

void solve(vector<int> &v) {
    int low = 0, high = v.size() - 1;
    quick_sort(v, low, high);
}

int main() {
    vector<int> v = {5, 2, 3, 1};

    solve(v);

    for (int &el : v) {
        cout << el << ' ';
    }
    cout << '\n';

    return 0;
}