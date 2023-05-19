#include <iostream>
#include <climits>
#include <vector>
#include <math.h>
using namespace std;

// ---------------------------- Seive of Eratosthenes -----------------------
void sieve(long long n, vector<long long> &primes){
    vector<bool> isPrime(n+1, true);
    isPrime[0] = isPrime[1] = false;
    for(long long i=2; i<=n; i++){
        if(isPrime[i]){
            primes.push_back(i);
            for(long long j=i*i; j<=n; j+=i){
                isPrime[i] = false;
            }
        }
    }
}

// Time Complexity: O(n*log(log(n)))
// Auxiliary space: O(n)

// ---------------------------- Segemented Sieve -----------------------
long long primeProduct(long long L, long long R){
        vector<long long> primes;
        long long sg = sqrt(R);
        sieve(sg, primes);

        vector<bool> isPrime(R-L+1, true);
        if(L==1){
            isPrime[0] = false; // 1->false
        }

        else if(L==0){
            isPrime[0] = false; // 0->false
            isPrime[1] = false; // 1-> false
        }

        for(long long p: primes){
            long long sm = L/p*p;
            if(sm<L){
                sm+=p;
            }

            for(long long m=sm; m<=R; m+=p){
                if(m!=p){
                    isPrime[m-L] = false;
                }
            }
        }

        long long ans=1;
        for(int i=L; i<=R; i++){
            if(isPrime[i-L]){
                ans*=i;
                ans = (ans) % 1000000007;
            }
        }

        return ans;
    }

// Time Complexity: O(h*log(log(h)))
// Auxiliary space: O(root(h)

int main(){

    cout << primeProduct(1, 20);

}