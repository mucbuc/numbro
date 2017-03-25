/*
om636
Copyright (c) 2013 by Mark Busenitz
www.github.com/mucbuc
*/

#ifndef additive_H_8900700
#define additive_H_8900700

#include <tuple>

#include <lib/context/src/interface.h>
#include <lib/context/src/default_subject.h>
#include <lib/numbro/src/observer.h>

namespace om636
{
    namespace additive
    {
        template<class T>
        struct policy
        : public math::observer< T >
        {
            typedef T context_type;
            typedef math::observer<context_type> observer_type;
            typedef decltype( std::tuple_cat( typename default_subject::traits<context_type>::value_type(), std::tuple< observer_type * >(0) ) ) value_type;
            typedef typename std::tuple_element<0, value_type>::type positive_type;
            typedef typename std::tuple_element<1, value_type>::type negative_type;
            
            template<class V>
            static value_type on_init(V &);
            
            template<class V, class W>
            static value_type on_init(V &, const W &);
            
        	template<class V>
            static V to_value(const context_type &);
            
            static positive_type & pos_ref(context_type &);
            static const positive_type & pos_ref(const context_type &);
            static negative_type & neg_ref(context_type &);
            static const negative_type & neg_ref(const context_type &);
            static observer_type * & state(context_type &);
            static observer_type * state(const context_type &);
                        
            static observer_type * evaluate(context_type &);
            static observer_type * evaluate(const context_type &);
            
            static observer_type * unknown();
            static observer_type * zero();
            static observer_type * positive();
            static observer_type * negative();
        };
        
        namespace Private
        {
            
            // unknown_state
            template<class T>
            struct unknown_state
            : public math::value_observer< typename T::policy_type >
            {
                // types
                typedef T context_type;
                typedef math::value_observer< typename T::policy_type > subject_policy;
                using subject_policy::unknown;
                using subject_policy::zero;
                using subject_policy::negative;
                using subject_policy::evaluate;
                using subject_policy::pos_ref;
                using subject_policy::neg_ref;
                using subject_policy::state;
                
                // comparisons
                bool on_equal(const context_type &, const context_type &) const;
                int on_cmp(const context_type &, const context_type &) const;
                int on_sign(const context_type &) const;
                
                // modifiers
                void on_add(context_type &, const context_type &) const;
                void on_subtract(context_type &, const context_type &) const;
                void on_mult(context_type &, const context_type &) const;
                void on_divide(context_type &, const context_type &) const;
                void on_remainder(context_type &, const context_type &) const;
                void on_inc(context_type &) const;
                void on_dec(context_type &) const;
                void on_invert(context_type &) const;
            };
            
            // zero_state
            template<class T>
            struct zero_state
            : public math::value_observer< typename T::policy_type >
            {
                // types
                typedef T context_type;
                typedef math::value_observer< typename T::policy_type > subject_policy;
                using subject_policy::unknown;
                using subject_policy::zero;
                using subject_policy::positive;
                using subject_policy::negative;
                using subject_policy::evaluate;
                using subject_policy::pos_ref;
                using subject_policy::neg_ref;
                using subject_policy::on_swap;
                using subject_policy::state;
                
                // comparisons
                bool on_equal(const context_type &, const context_type &) const;
                int on_cmp(const context_type &, const context_type &) const;
                int on_sign(const context_type &) const;
                
                // modifiers
                void on_add(context_type &, const context_type &) const;
                void on_subtract(context_type &, const context_type &) const;
                void on_mult(context_type &, const context_type &) const;
                void on_divide(context_type &, const context_type &) const;
                void on_remainder(context_type &, const context_type &) const;
                void on_inc(context_type &) const;
                void on_dec(context_type &) const;
                void on_invert(context_type &) const;
            };
            
            // positive_state
            template<class T>
            struct positive_state
            : public math::value_observer< typename T::policy_type >
            {
                // types
                typedef T context_type;
                typedef math::value_observer< typename T::policy_type > subject_policy;
                using subject_policy::unknown;
                using subject_policy::zero;
                using subject_policy::negative;
                using subject_policy::evaluate;
                using subject_policy::pos_ref;
                using subject_policy::neg_ref;
                using subject_policy::state;
                
                // comparisons
                bool on_equal(const context_type &, const context_type &) const;
                int on_cmp(const context_type &, const context_type &) const;
                int on_sign(const context_type &) const;
                
                // modifiers
                void on_add(context_type &, const context_type &) const;
                void on_subtract(context_type &, const context_type &) const;
                void on_mult(context_type &, const context_type &) const;
                void on_divide(context_type &, const context_type &) const;
                void on_remainder(context_type &, const context_type &) const;
                void on_inc(context_type &) const;
                void on_dec(context_type &) const;
                void on_invert(context_type &) const;
            };
            
            // negative_state
            template<class T>
            struct negative_state
            : public math::value_observer< typename T::policy_type >
            {
                // types
                typedef T context_type;
                typedef math::value_observer< typename T::policy_type > subject_policy;
                using subject_policy::unknown;
                using subject_policy::zero;
                using subject_policy::positive;
                using subject_policy::negative;
                using subject_policy::evaluate;
                using subject_policy::pos_ref;
                using subject_policy::neg_ref;
                using subject_policy::state;
                
                // comparisons
                bool on_equal(const context_type &, const context_type &) const;
                int on_cmp(const context_type &, const context_type &) const;
                int on_sign(const context_type &) const;
                
                // modifiers
                void on_add(context_type &, const context_type &) const;
                void on_subtract(context_type &, const context_type &) const;
                void on_mult(context_type &, const context_type &) const;
                void on_divide(context_type &, const context_type &) const;
                void on_remainder(context_type &, const context_type &) const;
                void on_inc(context_type &) const;
                void on_dec(context_type &) const;
                void on_invert(context_type &) const;
            };
        
        } // Private
            
    } // additive
    
}   // om636
        
#include "additive.hxx"

#endif // additive_H_8900700	