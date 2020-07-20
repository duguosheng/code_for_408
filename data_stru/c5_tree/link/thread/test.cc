#include "threadtree.h"

#ifdef DONT_CREATE_NODE
#define DC DONT_CREATE_NODE
#elif
#define DC 0
#endif

int main(void) {
    ThreadTree ttree{1, 2, 4,  7, DC, DC, 8, DC, DC, DC,
                     3, 5, DC, 9, DC, DC, 6, DC, DC};
    ttree.InOrder();
}