#ifndef SUB_SCOPE__INCLUDE_GUARD__0p45545DD45GGH566867PIOIOWQXZCBNMIOPEW
	#define SUB_SCOPE__INCLUDE_GUARD__0p45545DD45GGH566867PIOIOWQXZCBNMIOPEW

#include <lib/sense/src/observer.h>

namespace om636
{
    template<class T>
	class sub_scope
		: public const_observer< T >
    {
	public:
		// types
		typedef T context_type;
		typedef const_observer<context_type> base_type;
		
		sub_scope() = delete;
		sub_scope(const sub_scope &) = delete;	
		sub_scope & operator=(const sub_scope & ) = delete; 

		virtual ~sub_scope();
       
	protected:
		sub_scope(context_type &);
        context_type & context() const; 
        
	private:
		context_type & m_context; 
    };
	
} // om636

#include "sub_scope.hxx"

#endif // SUB_SCOPE__INCLUDE_GUARD__0p45545DD45GGH566867PIOIOWQXZCBNMIOPEW