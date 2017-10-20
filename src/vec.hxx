
namespace om636 {
/////////////////////////////////////////////////////////////////////////////////////////////
// vec<T>
/////////////////////////////////////////////////////////////////////////////////////////////
template <class C>
bool vec<C>::on_equal(const context_type& lhs, const context_type& rhs)
{
    return traverse_parallel_if(lhs.value_ref(), rhs.value_ref(), equal()).result();
}

/////////////////////////////////////////////////////////////////////////////////////////////
template <class C>
int vec<C>::on_cmp(const context_type& lhs, const context_type& rhs)
{
    return traverse_parallel_if(lhs.value_ref(), rhs.value_ref(), compare()).result();
}

/////////////////////////////////////////////////////////////////////////////////////////////
template <class C>
int vec<C>::on_sign(const context_type& lhs)
{
    return traverse_if(lhs.value_ref(), compare()).result();
}

/////////////////////////////////////////////////////////////////////////////////////////////
//	template<class C>
//	template<class T>
//	void vec<C>::outer_product(const T & rhs)
//	{	/*traverse_combinations( lhs.value_ref(), rhs, product() );*/ 	}

/////////////////////////////////////////////////////////////////////////////////////////////
template <class C>
void vec<C>::on_add(context_type& lhs, const context_type& _n)
{
    traverse_parallel(lhs.value_ref(), _n.value_ref(), sum());
}

/////////////////////////////////////////////////////////////////////////////////////////////
template <class C>
void vec<C>::on_subtract(context_type& lhs, const context_type& _n)
{
    traverse_parallel(lhs.value_ref(), _n.value_ref(), difference());
}

/////////////////////////////////////////////////////////////////////////////////////////////
template <class C>
void vec<C>::on_mult(context_type& lhs, const context_type& _n)
{
    traverse_parallel(lhs.value_ref(), _n.value_ref(), product());
}

/////////////////////////////////////////////////////////////////////////////////////////////
template <class C>
void vec<C>::on_divide(context_type& lhs, const context_type& _n)
{
    traverse_parallel(lhs.value_ref(), _n.value_ref(), quotient());
}

/////////////////////////////////////////////////////////////////////////////////////////////
template <class C>
void vec<C>::on_remainder(context_type& lhs, const context_type& _n)
{
    traverse_parallel(lhs.value_ref(), _n.value_ref(), remainder());
}

/////////////////////////////////////////////////////////////////////////////////////////////
template <class C>
template <class T>
void vec<C>::power(T& _m, const T& _n)
{
}

/////////////////////////////////////////////////////////////////////////////////////////////
template <class C>
template <class T, class U>
T vec<C>::reduce(U w)
{
    return std::get<1>(w.value_ref().template reduce<T>(w));
}

} // om636
