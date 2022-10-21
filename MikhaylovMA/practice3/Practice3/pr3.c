#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define n 5
int main() {
	short nums[n];
	short length;
	srand((unsigned int)time(NULL));

	do {
		printf("Insert number length (2-5)");
		scanf("%hd", &length);
	} while (length < 2 || length > 5);

	for (short i = 0; i < n - 1; i++) {
		for 
	}
}