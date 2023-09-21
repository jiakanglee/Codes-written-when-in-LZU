#include "func.h"
long long factorial(int x) {//recursive
    if (x == 0 || x == 1)
        return 1;
    return x * factorial(x - 1);
}
long long factorial_for(int x) {//nonrecursive
    long long ans = 1;
    for (int i = 1; i <= x; i++) {
        ans *= i;
    }
    return ans;
}