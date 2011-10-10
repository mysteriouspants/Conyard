//! Created by Chris Miller on 10 October 2011.
//! Copyright 2011 Chris Miller. All rights reserved.

#include "int-vector.gen.h"

#include <stdio.h>

int main(int argc, char **argv) {
    printf("Creating vector... \n");
    struct int_vector* v = int_vector_create(10);
    for (int i=0; i<10; ++i) {
        int_vector_push_back(v, i);
        printf("  Added element %d to vector\n", i);
    }
    int_vector_free(v);
    printf("Freed vector.\n");
    return 0;
}
