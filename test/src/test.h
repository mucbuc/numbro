#include <fstream>
#include <functional>
#include <iostream>
#include <vector>

#include <lib/context/src/interface.h>
#include <lib/context/test/src/base.h>
#include <lib/numbro/src/additive.h>
#include <lib/numbro/src/multiplicative.h>
#include <lib/numbro/src/range.h>
#include <lib/numbro/src/vec.h>
#include <lib/sense/src/subject.h>

namespace
{
    template<class T>
    using additive_type = om636::state_subject< om636::additive::policy< T > >;

    template<class T>
    using multiplicative_type = om636::state_subject< om636::multiplicative::policy< T > >;
 
    void run_matrix_test()
    {
		using namespace std;
		using namespace om636;

    	typedef context< tuple< unsigned, unsigned, unsigned >, vec > context_type;
		
		context_type a( make_tuple( 1, 2, 4 ) );
		a[om636::index<2>()] = 0;
		cout << a << endl;


		FOOTER;
    }

	template<class T>
	void run_math_test()
	{
		using namespace std;
		using namespace om636;
		
		typedef context< tuple< unsigned, unsigned >, additive_type > number_type1;
        tools::tester< number_type1 >::test_number();
        
		typedef context< tuple< int, int >, multiplicative_type > number_type2;
		tools::tester< number_type2 >::test_number();

		typedef context< tuple< number_type1, number_type1 >, multiplicative_type > number_type3;
		tools::tester< number_type3 >::test_number();
		
		typedef context< tuple< number_type2, number_type2 >, additive_type > number_type4;
		tools::tester< number_type4 >::test_number();

		FOOTER;
	}
}
