#ifndef TYPEUTILLS_H_PTVMMGE2WRT9
	#define TYPEUTILLS_H_PTVMMGE2WRT9

#include <tuple>

namespace om636
{
#if 0
    /////////////////////////////////////////////////////////////////////////////////////////////
	// is_builtin_type
	/////////////////////////////////////////////////////////////////////////////////////////////
    template<class T> 
    struct is_builtin_type
    {
        typedef std::tuple<
                             char, 
                             unsigned char,  
                             short,  
                             unsigned short, 
                             int,  
                             unsigned,  
                             long,  
                             unsigned long, 
                             long long, 
                             unsigned long long, 
                             float, 
                             double, 
                             double long > builtin_list_type;
        
        enum { result = type_find<builtin_list_type, T>::result < std::tuple_size<builtin_list_type>::value };
    };
#endif 
    
	/////////////////////////////////////////////////////////////////////////////////////////////
	// if_then_else 
	/////////////////////////////////////////////////////////////////////////////////////////////
	template<bool, class T, class U>
	struct if_then_else
	{	typedef T result_type;	};

	/////////////////////////////////////////////////////////////////////////////////////////////
	template<class T, class U>
	struct if_then_else<false, T, U> 
	{	typedef U result_type;	};

	/////////////////////////////////////////////////////////////////////////////////////////////
	// switch_const 
	/////////////////////////////////////////////////////////////////////////////////////////////
	template<class T>
	struct switch_const
	{	typedef const T result_type; };

	/////////////////////////////////////////////////////////////////////////////////////////////
	template<class T>
	struct switch_const< const T >
	{	typedef T result_type; };

	/////////////////////////////////////////////////////////////////////////////////////////////
	// add_reference 
	/////////////////////////////////////////////////////////////////////////////////////////////
	template<class T>
	struct add_reference
	{	typedef T & result_type; 	};

	/////////////////////////////////////////////////////////////////////////////////////////////
	template<class T>
	struct add_reference<T &>
	{	typedef T & result_type; 	};

	/////////////////////////////////////////////////////////////////////////////////////////////
	// add_const
	/////////////////////////////////////////////////////////////////////////////////////////////
	template<class T>
	struct add_const
	{	typedef const T result_type; 	};

	/////////////////////////////////////////////////////////////////////////////////////////////
	template<class T>
	struct add_const<const T>
	{	typedef const T result_type; 	};

	/////////////////////////////////////////////////////////////////////////////////////////////
	template<class T>
	struct add_const<const T &>
	{	typedef const T & result_type; 	};

	/////////////////////////////////////////////////////////////////////////////////////////////
	// remove_pointer
	/////////////////////////////////////////////////////////////////////////////////////////////
	template<class T>
	struct remove_pointer
	{	typedef T result_type; 	};
    
	/////////////////////////////////////////////////////////////////////////////////////////////
	template<class T>
	struct remove_pointer<T *>
	{	typedef T result_type; 	};
  	
	/////////////////////////////////////////////////////////////////////////////////////////////
	// remove_reference
	/////////////////////////////////////////////////////////////////////////////////////////////
	template<class T>
	struct remove_reference
	{	typedef T result_type; 	};
    
	/////////////////////////////////////////////////////////////////////////////////////////////
	template<class T>
	struct remove_reference<T &>
	{	typedef T result_type; 	};
  	
    /////////////////////////////////////////////////////////////////////////////////////////////
	// ctor_traits
	/////////////////////////////////////////////////////////////////////////////////////////////
    template<class T>
	struct ctor_traits
	{	typedef typename add_reference< typename add_const< T >::result_type >::result_type result_type; };
    
	/////////////////////////////////////////////////////////////////////////////////////////////
	template<class T>
	struct ctor_traits<T &>
	{	typedef T & result_type;	};
    
	/////////////////////////////////////////////////////////////////////////////////////////////
	template<class T>
	struct ctor_traits<const T &>
	{	typedef const T & result_type; 	};
    
    template<class, class>
    struct tuple_append;
    
    template<class ... T, class U>
    struct tuple_append< std::tuple< T ... >, U >
    {
        typedef std::tuple< T ..., U > type;
    };
    
    
}	// om636
	
#endif // TYPEUTILLS_H_PTVMMGE2WRT9