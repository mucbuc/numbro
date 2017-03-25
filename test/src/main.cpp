#include <iostream>

#include <plank/src/test.h>
#include <tmp/src/test.h>

int main(int argc, const char * argv[])
{
    using namespace om636;

	run_math_test<void>();

	run_matrix_test();
	return 0;
}