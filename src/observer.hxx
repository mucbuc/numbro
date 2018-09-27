
namespace om636 {
namespace math {
#pragma mark -
#pragma mark value_observer
#pragma mark -

    /////////////////////////////////////////////////////////////////////////////////////////////
    // value_observer
    /////////////////////////////////////////////////////////////////////////////////////////////
    template <class T>
    bool value_observer<T>::on_swap(context_type& lhs, context_type& rhs) const
    {
        using std::swap;

        swap(lhs.value_ref(), rhs.value_ref());
        swap(lhs.subject_ref(), rhs.subject_ref());
        return 0;
    }

} // math

} // om636
