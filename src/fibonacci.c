#include <stdio.h>
#include <stdlib.h>

int fib(int n) {
    int a = 1, b = 1;
    int tmp, i;
    
    for (i = 2; i < n; i++) {
	tmp = a;
	a = b;
	b = b + tmp;	
    }
    return b;
}


int main(int argc, char* argv[]) {
    int n;
    printf("Which Fibonacci number would you like? ");
    scanf("%d", &n);

    int res = fib(n);
    printf("%d \n", res);
}

