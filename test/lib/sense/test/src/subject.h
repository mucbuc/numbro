#include <iostream>
#include <string>

#include <lib/context/src/interface.h>
#include <lib/sense/src/observer/dynamic.h>
#include <lib/sense/src/observer/same_scope.h>
#include <lib/sense/src/observer/sub_scope.h>
#include <lib/sense/src/subject.h>

namespace {
template <class T>
using basic_const_subject = om636::basic_subject<T, om636::const_observer>;

template <class T>
using safe_const_subject = om636::safe_subject<basic_const_subject<T>>;

template <class T>
using basic_subject = om636::basic_subject<T, om636::observer>;

template <class T>
using safe_subject = om636::safe_subject<basic_subject<T>>;

template <class T>
using detachable_subject = om636::detachable_subject<
    om636::safe_subject<
        basic_subject<T>>>;

template <class T>
struct test_observer
    : T {
    typedef T base_type;
    typedef typename base_type::context_type context_type;

    test_observer(context_type& s)
        : base_type(s)
        , m_swapped(0)
    {
    }

    virtual ~test_observer() = default;

    virtual void on_swap(const context_type& lhs, const context_type&)
    {
        m_swapped = 1;
    }

    void reset()
    {
        m_swapped = 0;
    }

    bool swapped()
    {
        return m_swapped;
    }

private:
    bool m_swapped;
};

template <template <class> class T, class U>
void test_swap()
{
    using namespace om636;

    typedef U context_type;
    typedef T<context_type> base_type;

    context_type c;
    test_observer<base_type> o(c);
    o.reset();

    ASSERT(!o.swapped());
    c = 0;
    ASSERT(o.swapped());
    FOOTER;
}

template <class T>
struct test_observer2
    : test_observer<om636::dynamic<T>> {
    typedef test_observer<om636::dynamic<T>> base_type;
    using base_type::context;

    test_observer2(T& s)
        : base_type(s)
    {
    }

    virtual ~test_observer2() = default;

    virtual void on_swap(const T& lhs, const T& rhs)
    {
        base_type::context()->detach(*this);
        base_type::on_swap(lhs, rhs);
    }
};

template <template <class> class T>
void test_detach_while_swap()
{
    using namespace om636;

    typedef context<int, T> context_type;
    typedef test_observer2<context_type> observer_type;

    context_type c;
    observer_type o(c);

    o.reset();

    ASSERT(!o.swapped());

    try {
        c = 0;
    } catch (typename context_type::locked) {
        FOOTER;
        return;
    }

    ASSERT(0);
}

template <template <class> class T>
void test_subject_invalidate()
{
    using namespace om636;

    typedef context<int, T> context_type;
    typedef test_observer2<context_type> observer_type;

    context_type* c(new context_type());
    observer_type o(*c);

    ASSERT(c == o.context());

    delete c;

    ASSERT(!o.context());
    FOOTER;
}

template <class T>
struct test_observer3
    : test_observer<om636::dynamic<T>> {
    typedef test_observer<om636::dynamic<T>> base_type;

    test_observer3(T& s)
        : base_type(s)
    {
    }

    virtual ~test_observer3()
    {
    }

    virtual void on_swap(const T& lhs, const T& rhs)
    {
        *base_type::context() = 1;
        base_type::on_swap(lhs, rhs);
    }
};

template <template <class> class T>
void test_swap_while_swap()
{
    using namespace om636;

    typedef context<int, T> context_type;
    typedef test_observer3<context_type> observer_type;

    context_type c;
    observer_type o(c);

    try {
        c = 0;
    } catch (typename context_type::locked) {
        FOOTER;
        return;
    }

    ASSERT(0);
}

template <class T>
void run_observer_test()
{
    using namespace om636;

    test_swap<same_scope, context<int, basic_const_subject>>();
    test_swap<sub_scope, context<int, basic_const_subject>>();

    test_swap<same_scope, context<int, safe_const_subject>>();
    test_swap<sub_scope, context<int, safe_const_subject>>();

    test_swap<dynamic, context<int, basic_subject>>();
    test_swap<dynamic, context<int, safe_subject>>();

    test_detach_while_swap<safe_subject>();
    test_swap_while_swap<safe_subject>();

    test_subject_invalidate<detachable_subject>();
}
}