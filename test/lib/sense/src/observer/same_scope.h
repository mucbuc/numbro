#ifndef SAME_SCOPE_H__INCLUDE_GUARD__96545HHFGHDYIRYUIR
#define SAME_SCOPE_H__INCLUDE_GUARD__96545HHFGHDYIRYUIR

#include <lib/sense/src/observer.h>

namespace om636 {
template <class T>
class same_scope
    : public const_observer<T> {
public:
    // types
    typedef T context_type;
    typedef const_observer<context_type> base_type;

    same_scope() = delete;
    same_scope(const same_scope&) = delete;
    same_scope& operator=(const same_scope&) = delete;

    virtual ~same_scope() = default;

protected:
    same_scope(context_type&);
};

} // om636

#include "same_scope.hxx"

#endif // SAME_SCOPE_H__INCLUDE_GUARD__96545HHFGHDYIRYUIR