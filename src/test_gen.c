#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "sfmt.h"

int main(int argc, char *argv[]) {
    uint32_t seed;
    uint64_t hi, low;
    int i;

    if (argc == 1) {
	seed = 1234;
    } else {
	seed = strtol(argv[1], NULL, 10);
    }

    init_gen_rand(seed);
    printf("non structure version\n");
    printf("128 bit output\n");
    for (i = 0; i < 500; i++) {
	printf("%20llu ", gen_rand128(&hi, &low));
	if (i % 3 == 2) {
	    printf("\n");
	}
    }
    printf("\n");
    printf("32 bit output\n");
    for (i = 0; i < 1000; i++) {
	printf("%10u ", gen_rand32());
	if (i % 5 == 4) {
	    printf("\n");
	}
    }
    return 0;
}
