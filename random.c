#include <stdlib.h>
#include "random.h"

int random_range(int lower_bound, int upper_bound) {
    return rand() % (upper_bound - lower_bound + 1) + lower_bound;
}
