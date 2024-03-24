#include <iostream>
#include <vector>

using namespace std;

void segmentedSieve(int n) {
    const int S = 10000; // Segment size
    vector<bool> prime(S, true);
    vector<int> primes;

    for (int base = 0; base < n; base += S) {
        fill(prime.begin(), prime.end(), true);
        int limit = min(n - base, S);
        for (int i = 2; i * i <= n; i++) {
            for (int j = max(i * i, (base + i - 1) / i * i); j < base + limit; j += i) {
                prime[j - base] = false;
            }
        }
        for (int i = max(2, base); i < base + limit; i++) {
            if (prime[i - base]) {
                primes.push_back(i);
            }
        }
    }

    for (int p : primes) {
        cout << p << " ";
    }
}

int main() {
    int n = 100; // Generate primes up to n
    segmentedSieve(n);
    return 0;
}
