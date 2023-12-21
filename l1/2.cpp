#include <iostream>
#include <boost/type_index.hpp>

using namespace std;

template <typename T>
// void testFunc(T& val)
void testFunc(T&& val)
{
	cout << "----------begin----------" << endl;
	using boost::typeindex::type_id_with_cvr;
	cout << "T=" << type_id_with_cvr<T>().pretty_name() << endl;
	cout << "val=" << type_id_with_cvr<decltype(val)>().pretty_name() << endl;
	cout << "-----------end-----------" << endl;
}

// 完美转发
template <typename F, typename T1, typename T2>
void myTempFunc(F f, T1&& t1, T2&& t2)
{
	f(std::forward<T1>(t1), std::forward<T2>(t2));
}

int main()
{
	int i = 10;

	testFunc(i);  // i是左值   T=int &, val = int&
	testFunc(10); // 100是右值 T=int  , val = int&&

	return 0;
}