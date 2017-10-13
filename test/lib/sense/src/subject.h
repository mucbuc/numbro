/* 
om636
Copyright (c) 2013 by Mark Busenitz
www.github.com/mucbuc

objective: 
    collection of subject policies

*/

#ifndef SUBJECT_H__3OinTKlusSf57wk9G41geIdYXzUEVv
#define SUBJECT_H__3OinTKlusSf57wk9G41geIdYXzUEVv

#include <algorithm>
#include <vector>

#include <lib/context/src/default_subject.h>

namespace om636 {
// no attach/detach while update
template <class T, template <class> class U>
struct basic_subject
    : default_subject::policy<T> {
    typedef T context_type;
    typedef typename default_subject::traits<context_type>::value_type value_type;
    typedef U<context_type> observer_type;

    basic_subject();
    virtual ~basic_subject();
    void attach(observer_type&);
    void detach(observer_type&);

protected:
    virtual void on_swap(context_type&, context_type&);

    template <class V>
    static value_type on_init(V&);

    template <class V, class W>
    static value_type on_init(V&, const W&);

    template <class V>
    static V to_value(const context_type&);

protected:
    typedef std::vector<observer_type*> container_type;
    typedef typename container_type::iterator iterator;

    container_type& observers();
    const container_type& observers() const;

private:
    container_type m_observers;
};

template <class T>
struct safe_subject
    : public T {
    struct locked {
    };

    typedef T base_type;
    using typename base_type::context_type;
    using typename base_type::observer_type;
    using base_type::observers;

    safe_subject();
    virtual ~safe_subject() = default;

    void attach(observer_type&);
    void detach(observer_type&);
    virtual void on_swap(context_type&, context_type&);

private:
    bool m_locked;
};

template <class T>
struct detachable_subject
    : public T {
    detachable_subject() = default;
    virtual ~detachable_subject();
    typedef T base_type;
    using typename base_type::observer_type;
    using base_type::observers;
};

template <class T>
struct state_subject
    : private T {
    // types
    typedef T policy_type;

    typedef typename policy_type::value_type value_type;
    typedef typename policy_type::context_type context_type;
    using policy_type::on_init;
    using policy_type::to_value;
    using policy_type::state;

    virtual ~state_subject();

    // comparisons
    virtual bool on_equal(const context_type&, const context_type&) const;
    virtual int on_cmp(const context_type&, const context_type&) const;
    virtual int on_sign(const context_type&) const;

    // modifiers
    virtual bool on_swap(context_type&, context_type&) const;
    virtual void on_add(context_type&, const context_type&) const;
    virtual void on_subtract(context_type&, const context_type&) const;
    virtual void on_mult(context_type&, const context_type&) const;
    virtual void on_divide(context_type&, const context_type&) const;
    virtual void on_remainder(context_type&, const context_type&) const;
    virtual void on_inc(context_type&) const;
    virtual void on_dec(context_type&) const;
    virtual void on_invert(context_type&) const;
};

// template<class T>
// struct batch_subject
// : default_subject::policy< T >
// {
//     typedef T context_type;
//     typedef typename default_subject::traits<context_type>::value_type value_type;
//     typedef U< context_type > * observer_type;

//     virtual void on_swap(context_type &, context_type &);

//     template<class V>
//     static value_type on_init(V &);

//     template<class V, class W>
//     static value_type on_init(V &, const W &);

//     template<class V>
//     static V to_value(const context_type &);
// };

} // om636

#include "subject.hxx"
#endif // SUBJECT_H__3OinTKlusSf57wk9G41geIdYXzUEVv