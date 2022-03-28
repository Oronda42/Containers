
template<bool B, class T = void>
struct enable_if {};
 
template<class T>
struct enable_if<true, T> { typedef T type; };

template <class T> 
struct is_integral
{

}

struct false_type
{

}

struct true_type
{

}