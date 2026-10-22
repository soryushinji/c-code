#include <stdio.h>

int main(void) {
	for (int i = 1; i <= 10000; ++i) {
		printf("int generated_line_%05d = %d;\n", i, i);
	}
	return 0;
}
