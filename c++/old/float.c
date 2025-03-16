#include <stdio.h>
#include <stdlib.h>

union ss {
	int d;
	unsigned u;
};

void int_to_unsigned(int d) {
	union ss du;
	du.d = d;
	printf("du.d = %d\n", du.d);
	printf("du.u = %u\n", du.u);
}

int main(int argc, char *argv[]) {
	int d_num;
	if (argc == 2) {
		d_num = atoi(argv[1]);
	} 
	else return 0;

	int_to_unsigned(d_num);
	return 0;
}