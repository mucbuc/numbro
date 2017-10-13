#ifndef DYNAMIC_H__INCLUDE_GUARD__PZZQMMGU96545HHFGHDYIR
#define DYNAMIC_H__INCLUDE_GUARD__PZZQMMGU96545HHFGHDYIR

#include <lib/sense/src/observer.h>

namespace om636 {

template <class T>
struct dynamic
    : public observer<T> {
    // types
    typedef T context_type;
    typedef observer<context_type> base_type;

    dynamic& operator=(const dynamic&) = delete;
    virtual ~dynamic();

protected:
    dynamic();
    dynamic(context_type&);
    dynamic(const dynamic&);

    void detach();
    context_type* context() const;

private:
    context_type* m_context;
};

} // om636

#include "dynamic.hxx"

#endif // DYNAMIC_H__INCLUDE_GUARD__PZZQMMGU96545HHFGHDYIR