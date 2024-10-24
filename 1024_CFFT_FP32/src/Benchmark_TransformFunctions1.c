#include "riscv_math.h"
#include <stdio.h>
#include "riscv_const_structs.h"
#include "1024_fp32_input.h"

#define PRINT_OUTPUT
#define PRINT_F32(X,Y) \
    printf("\n"); \
    for(int i = 0; i < (Y); i++) { \
        printf("%f  ", (float)(X[i] * 100)); \
        if ((i + 1) % 2 == 0) { \
            printf("\n"); \
        } \
    }

/*float32_t testInput_f32_2048[2048];  

void load_2048() {
    FILE *file = fopen("random_numbers.txt", "r");
    if (file == NULL) {
        fprintf(stderr, "Could not open file random_numbers.txt\n");
        return;
    }
    int ARRAY_SIZE = 2048;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (fscanf(file, "%f", &testInput_f32_2048[i]) != 1) {
            fprintf(stderr, "Error reading number at index %d\n", i);
            fclose(file);
            return;
        }
    }

    fclose(file);
}*/

uint32_t fftSize = 1024;
uint32_t ifftFlag = 0;
uint32_t doBitReverse = 1;


int32_t main(void)
{
  __asm__ volatile ("xor x0, x0, x0");
  riscv_cfft_f32(&riscv_cfft_sR_f32_len1024, testInput_f32_1024, ifftFlag, doBitReverse);
  __asm__ volatile ("xor x0, x0, x0");
#ifdef PRINT_OUTPUT
  PRINT_F32(testInput_f32_1024,fftSize*2);
#endif
 return 0;
}



