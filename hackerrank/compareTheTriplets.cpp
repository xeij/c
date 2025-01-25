#include <iostream>
#include <vector>

using namespace std;

vector<int> compareTriplets(vector<int> a, vector<int> b) {
    int alice = 0, bob = 0;

    for (int i = 0; i < 3; i++) {
        if (a[i] > b[i]) {
            alice++;
        } else if (a[i] < b[i]) {
            bob++;
        }
    }

    return {alice, bob};
}

int main() {
    vector<int> a(3), b(3);

    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 3; i++) {
        cin >> b[i];
    }
    vector<int> result = compareTriplets(a, b);

    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
