#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getHighestBase(int num);  // fn for find highest base
void plotFrequencyDistribution(int frequency[]);  // fn for frequency

int main() {
    int numIntegers = 500;
    int numDigits = 4;
    int frequency[11] = {0};
    int lowervalue = 1000;
    int uppervalue = 9999;
    int integers[numIntegers];
    srand(time(0));

    for (int i = 0; i < numIntegers; i++) {
        integers[i] = (rand() % (uppervalue - lowervalue + 1)) + lowervalue;
        int highest_base = getHighestBase(integers[i]);
        frequency[highest_base]++;
    }

    for (int i = 0; i < numIntegers; i++) {
        printf("Integer %3d: %4d, Highest Base: %2d\n", i + 1, integers[i], getHighestBase(integers[i]));
    }
    plotFrequencyDistribution(frequency);
    return 0;
}

int getHighestBase(int num) {
    int highestBase = 0;
    while (num > 0) {
        int digit = num % 10;
        if (digit > highestBase) {
            highestBase = digit;
        }
        num /= 10;
    }
    return highestBase + 1;
}

void plotFrequencyDistribution(int frequency[]) {
    printf("Frequency Distribution:\n");
    for (int base = 2; base <= 10; base++) {
        printf("%2d | ", base);
        for (int i = 0; i < frequency[base]; i++) {
            printf("*");
        }
        printf("\n");
    }
}