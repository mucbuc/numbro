#ifndef OBSERVERH__INCLUDE_GUARD__OT6RUYIRYUIR
#define OBSERVERH__INCLUDE_GUARD__OT6RUYIRYUIR

namespace om636 {
template <class T>
struct const_observer {
    // types
    typedef T context_type;

    virtual ~const_observer() = default;
    virtual void on_swap(const context_type&, const context_type&) = 0;
};

template <class T>
struct observer
    : const_observer<T> {
    // types
    typedef T context_type;
    typedef const_observer<context_type> base_type;

    virtual ~observer() = default;
    virtual void detach() = 0;
};

} // om636

#endif // OBSERVERH__INCLUDE_GUARD__OT6RUYIRYUIR