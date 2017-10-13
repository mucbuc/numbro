/*
om636
Copyright (c) 2013 by Mark Busenitz
www.github.com/mucbuc
*/

#ifndef MULTIPLICATIVE_H_8900700
#define MULTIPLICATIVE_H_8900700

#include <lib/drop/interface.h>
#include <lib/numbro/src/observer.h>

namespace om636 {
namespace multiplicative {
    template <class T>
    struct policy
        : public math::observer<T> {
        typedef T context_type;
        typedef math::observer<context_type> observer_type;
        typedef decltype(tuple_cat(typename default_subject::traits<context_type>::value_type(), std::tuple<observer_type*>(0))) value_type;
        typedef typename std::tuple_element<0, value_type>::type numerator_type;
        typedef typename std::tuple_element<1, value_type>::type denumerator_type;

        template <class V>
        static value_type on_init(V&);

        template <class V, class W>
        static value_type on_init(V&, const W&);

        template <class V>
        static V to_value(const context_type&);

        static numerator_type& num_ref(context_type&);
        static const numerator_type& num_ref(const context_type&);
        static denumerator_type& den_ref(context_type&);
        static const denumerator_type& den_ref(const context_type&);
        static observer_type*& state(context_type&);
        static observer_type* state(const context_type&);

        static observer_type* evaluate(context_type&);
        static observer_type* evaluate(const context_type&);

        static observer_type* not_factored();
        static observer_type* unit();
        static observer_type* factored();
    };

    namespace Private {

        // not_factored
        template <class T>
        struct not_factored_state
            : public math::value_observer<typename T::policy_type> {
            // types
            typedef T context_type;
            typedef math::value_observer<typename T::policy_type> subject_policy;

            using subject_policy::evaluate;
            using subject_policy::num_ref;
            using subject_policy::den_ref;
            using subject_policy::state;

            // comparisons
            bool on_equal(const context_type&, const context_type&) const;
            int on_cmp(const context_type&, const context_type&) const;
            int on_sign(const context_type&) const;

            // modifiers
            void on_add(context_type&, const context_type&) const;
            void on_subtract(context_type&, const context_type&) const;
            void on_mult(context_type&, const context_type&) const;
            void on_divide(context_type&, const context_type&) const;
            void on_remainder(context_type&, const context_type&) const;
            void on_inc(context_type&) const;
            void on_dec(context_type&) const;
            void on_invert(context_type&) const;
        };

        // m_unit
        template <class T>
        struct unit_state
            : public math::value_observer<typename T::policy_type> {
            // types
            typedef T context_type;
            typedef math::value_observer<typename T::policy_type> subject_policy;

            using subject_policy::not_factored;
            using subject_policy::evaluate;
            using subject_policy::num_ref;
            using subject_policy::den_ref;
            using subject_policy::state;

            // comparisons
            bool on_equal(const context_type&, const context_type&) const;
            int on_cmp(const context_type&, const context_type&) const;
            int on_sign(const context_type&) const;

            // modifiers
            void on_add(context_type&, const context_type&) const;
            void on_subtract(context_type&, const context_type&) const;
            void on_mult(context_type&, const context_type&) const;
            void on_divide(context_type&, const context_type&) const;
            void on_remainder(context_type&, const context_type&) const;
            void on_inc(context_type&) const;
            void on_dec(context_type&) const;
            void on_invert(context_type&) const;
        };

        // factored
        template <class T>
        struct factored_state
            : public math::value_observer<typename T::policy_type> {
            // types
            typedef T context_type;
            typedef math::value_observer<typename T::policy_type> subject_policy;

            using subject_policy::not_factored;
            using subject_policy::num_ref;
            using subject_policy::den_ref;
            using subject_policy::state;
            using subject_policy::evaluate;

            // comparisons
            bool on_equal(const context_type&, const context_type&) const;
            int on_cmp(const context_type&, const context_type&) const;
            int on_sign(const context_type&) const;

            // modifiers
            void on_add(context_type&, const context_type&) const;
            void on_subtract(context_type&, const context_type&) const;
            void on_mult(context_type&, const context_type&) const;
            void on_divide(context_type&, const context_type&) const;
            void on_remainder(context_type&, const context_type&) const;
            void on_inc(context_type&) const;
            void on_dec(context_type&) const;
            void on_invert(context_type&) const;
        };

    } // Private
} // multiplicative

} // om636

#include "multiplicative.hxx"

#endif // MULTIPLICATIVE_H_8900700