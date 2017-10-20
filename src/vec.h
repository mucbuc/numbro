/*
	type: 
		policy class

	objective:
		implement matrix arithmetic
	
	note: 
		- swap is implemented by template parameter C 
*/

#ifndef VEC_H_UYK009u098
#define VEC_H_UYK009u098

#include <tuple>

#include <lib/context/src/default_subject.h>
#include <lib/drop/mathfunctors.h>

namespace om636 {
template <class C>
struct vec
    : default_subject::policy<C> {
    // types
    typedef C context_type;
    typedef typename default_subject::traits<context_type>::value_type value_type;

    // constants
    enum { rank = std::tuple_size<value_type>::value };

    // // comparisons
    static bool on_equal(const context_type&, const context_type&);
    static int on_cmp(const context_type&, const context_type&);
    static int on_sign(const context_type&);

    // modifiers
    static bool on_swap(context_type&, context_type&);
    static void on_add(context_type&, const context_type&);
    static void on_subtract(context_type&, const context_type&);
    static void on_mult(context_type&, const context_type&);
    static void on_divide(context_type&, const context_type&);
    static void on_remainder(context_type&, const context_type&);

    static void on_inc(context_type&);
    static void on_dec(context_type&);
    static void on_invert(context_type&);

    template <class T>
    void outer_product(const T&) const;

    template <class T>
    static void power(T&, const T&);

    template <class T>
    static void evaluate(T&);

    template <class T, class U>
    T reduce(U);
};
} // om636

#include "vec.hxx"

#endif // VEC_H_UYK009u098