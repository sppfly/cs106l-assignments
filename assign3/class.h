#include <cstdint>
#include <initializer_list>
namespace assign3 {

template <typename T>
class vector {
private:
	T*      data;
	int32_t size;
	int32_t cap;

public:
	vector();
	vector(int32_t size);
	vector(std::initializer_list<T>);

	T& operator[]();

	~vector();
};

}; // namespace assign3
