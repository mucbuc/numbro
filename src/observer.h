/*
om636
Copyright (c) 2013 by Mark Busenitz
www.github.com/mucbuc

objective:
    - define interface
    - implement basic class
*/

#ifndef OBSERVER_H__I0WfEMGNJgydS3rDPBO9CuwlVFqoiT
#define OBSERVER_H__I0WfEMGNJgydS3rDPBO9CuwlVFqoiT

namespace om636 {
namespace math {
    template <class T>
    struct observer {
        // types
        typedef T context_type;

        virtual ~observer();

        // comparisons
        virtual bool on_equal(const context_type&, const context_type&) const = 0;
        virtual int on_cmp(const context_type&, const context_type&) const = 0;
        virtual int on_sign(const context_type&) const = 0;

        // modifiers
        virtual bool on_swap(context_type&, context_type&) const = 0;
        virtual void on_add(context_type&, const context_type&) const = 0;
        virtual void on_subtract(context_type&, const context_type&) const = 0;
        virtual void on_mult(context_type&, const context_type&) const = 0;
        virtual void on_divide(context_type&, const context_type&) const = 0;
        virtual void on_remainder(context_type&, const context_type&) const = 0;
        virtual void on_inc(context_type&) const = 0;
        virtual void on_dec(context_type&) const = 0;
        virtual void on_invert(context_type&) const = 0;
    };

    template <class T>
    struct value_observer
        : public T {
        // types
        typedef T base_type;
        typedef typename base_type::context_type context_type;

        virtual ~value_observer();
        virtual bool on_swap(context_type&, context_type&) const;
    };

} // math

} // om636

#include <lib/numbro/src/observer.hxx>

#endif // __OBSERVER_H__I0WfEMGNJgydS3rDPBO9CuwlVFqoiT