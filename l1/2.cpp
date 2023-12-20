#include <iostream>
#include <boost/type_index.hpp>

using namespace std;

template <typename T>
// void testFunc(T& val)
void testFunc(const T& val)
{
	cout << "----------begin----------" << endl;
	using boost::typeindex::type_id_with_cvr;
	cout << "T=" << type_id_with_cvr<T>().pretty_name() << endl;
	cout << "val=" << type_id_with_cvr<decltype(val)>().pretty_name() << endl;
	cout << "-----------end-----------" << endl;
}

int main2()
{
	testFunc(100);

	return 0;
}