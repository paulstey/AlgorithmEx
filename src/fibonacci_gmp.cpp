#include <iostream>
#include <gmp.h>

using namespace std;

void addvals(mpz_t& a, mpz_t& b, mpz_t& c) {
    mpz_t tmp;
    mpz_inits(tmp, NULL);
    mpz_set_str(tmp, "0", 10);

    mpz_add(c, a, b);
}

int main(void) {
    mpz_t a, b;
    mpz_inits(a, b, NULL);
    mpz_set_str(a, "999", 10);
    mpz_set_str(b, "998", 10);

    mpz_t c = a + b;
    mpz_out_str(stdout, 10, c);
}
