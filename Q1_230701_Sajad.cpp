#include<stdio.h>

int main() {
    int array[20][20] = {
    {  8,  2, 22, 97, 38, 15,  0, 40,  0, 75,  4,  5,  7, 78, 52, 12, 50, 77, 91,  8 },
    { 49, 49, 99, 40, 17, 81, 18, 57, 60, 87, 17, 40, 98, 43, 69, 48,  4, 56, 62,  0 },
    { 40, 67, 53, 88, 30,  3, 49, 13, 36, 65, 24, 68, 56,  1, 32, 56, 71, 37,  2, 36 },
    { 91, 22, 31, 16, 71, 51, 67, 63, 89, 41, 92, 24, 47, 32, 60, 99,  3, 45,  2, 44 },
    { 75, 32, 98, 81, 28, 64, 23, 67, 10, 26, 38, 67, 26, 20, 68,  2, 62, 12, 20, 95 },
    { 63, 24, 55, 58,  5, 66, 73, 99, 26, 21, 36, 23,  9, 75,  0, 76, 44, 36, 54, 22 },
    { 40, 40, 28, 66, 33, 13, 80, 33, 53, 78, 36, 84, 20, 35, 17, 12, 50, 40, 67, 59 },
    { 54, 70, 66, 18, 38, 64, 70, 94, 39, 63,  8, 40, 91, 66, 49, 94, 21, 97, 78, 96 },
    { 83, 14, 88, 34, 89, 63, 72, 20, 45, 35, 14,  0, 61, 33, 97, 34, 31, 33, 95, 78 },
    { 17, 53, 28, 22, 75, 31, 67, 15, 16, 39,  5, 42, 96, 35, 31, 47, 55, 86, 56,  0 },
    { 48, 35, 71, 89,  7,  5, 94,  3, 80,  4, 62, 16, 14,  9, 53, 56, 92, 58, 88, 24 },
    {  0, 17, 54, 24, 36, 29, 85, 57, 44, 44, 37, 44, 60, 21, 58, 51, 54, 17, 58, 19 },
    { 80, 81, 68,  5, 94, 47, 69, 28, 73, 92, 13, 86, 52, 17, 77,  4, 89, 55, 40,  4 },
    { 52,  8, 83, 97, 35, 99, 16,  7, 97,  8, 36, 68, 87, 57, 62, 20, 72,  3, 46,  4 },
    { 42, 16, 73, 38, 25, 39, 11, 24, 94, 72, 18,  8, 46, 29, 32, 40, 62, 76, 36, 20 },
    { 69, 36, 41, 72, 30, 23, 88, 34, 62, 99, 69, 82, 67, 59, 85, 74,  4, 36, 16, 20 },
    { 73, 35, 29, 78, 31,  1, 70, 54, 71, 83, 51, 90,  1, 74, 31, 49, 71, 48, 86, 81 },
    { 16, 22, 54, 51, 19, 67, 48, 10, 90, 81, 60, 78, 95, 40, 54, 84, 97, 39,  5, 42 },
    { 26, 26, 79, 33, 27, 98, 66, 33, 67, 46, 55, 12, 32, 63, 93, 53, 69, 11, 24, 94 },
    { 72, 18,  8, 46, 29, 32, 40, 62, 76, 36, 20, 69, 36, 41, 72, 30, 23, 88, 34, 62 }
};


    
    int sum = 1;
    long int MAX_sumC = 1;                                          // Maximum product horizontally
    long int MAX_sumR = 1;                                        // Maximum product vertically
    long int MAX_sumD1 = 1;                                   // Maximum product diagonally (top left to bottom right)
    long int MAX_sumD2 = 1;                                  // Maximum product diagonally (top right to bottom left)

                                                               // Loop for calculating maximum product horizontally
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            sum *= array[i][j];
            if ((j % 4) == 3) {
                if (sum > MAX_sumC) {
                    MAX_sumC = sum;
                }
                sum = 1;
            }
        }
    }

                                                                 // Loop for calculating maximum product vertically
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            sum *= array[j][i];
            if ((j % 4) == 3) {
                if (sum > MAX_sumR) {
                    MAX_sumR = sum;
                }
                sum = 1;
            }
        }
    }

                                                            // Loop for calculating maximum product diagonally (top left to bottom right)
    for (int i = 0; i < 20; i++) {
        sum *= array[i][i];
        if ((i % 4) == 3) {
            if (sum > MAX_sumD1) {
                MAX_sumD1 = sum;
            }
            sum = 1;
        }
    }

                                                          // Loop for calculating maximum product diagonally (top right to bottom left)
    for (int i = 0; i < 20; i++) {
        sum *= array[i][19 - i];
        if ((i % 4) == 3) {
            if (sum > MAX_sumD2) {
                MAX_sumD2 = sum;
            }
            sum = 1;
        }
    }

                                                                   // Find the maximum among the four values
    long int max_value = MAX_sumC;
    if (MAX_sumR > max_value) {
        max_value = MAX_sumR;
    }
    if (MAX_sumD1 > max_value) {
        max_value = MAX_sumD1;
    }
    if (MAX_sumD2 > max_value) {
        max_value = MAX_sumD2;
    }

    
    printf("MAX Product Horizontal = %ld\n", MAX_sumC);                //printing results
    printf("MAX Product Vertical  = %ld\n", MAX_sumR);
    printf("MAX Product top left to bottom right Diagonally  = %ld\n", MAX_sumD1);
    printf("MAX Product Top Right to bottom left Diagonally  = %ld\n", MAX_sumD2);
    printf("MAXIMUM VALUE: %ld\n", max_value);

    return 0;
}

