#include <cstdint>
#include <initializer_list>

template <typename T>
class myvector {
private:
	T*      data;
	int32_t size;
	int32_t cap;

public:
	myvector();
	myvector(int32_t size);
	myvector(std::initializer_list<T>);

	T&   operator[](int32_t i);
	void add(const T& elem);

	// copy construtor
	myvector(const myvector<T>&);
	// copy assignment
	myvector& operator=(const myvector<T>&);

	~myvector();
};

template <typename T>
myvector<T>::myvector()
    : data(nullptr)
    , size(0)
    , cap(0) {
}

template <typename T>
myvector<T>::myvector(int32_t size)
    : data { new T[size] }
    , size { size }
    , cap { size } {
}

template <typename T>
myvector<T>::myvector(std::initializer_list<T> init)
    : data { new T[init.size()] }
    , size { init.size() }
    , cap { init.cap() } {

	int32_t i = 0;
	for (auto& one : init) {
		*(data + i) = one;
		i++;
	}
}

template <typename T>
void myvector<T>::add(const T& elem) {
	*(this->data + size) = elem;
	size++;
}

template <typename T>
T& myvector<T>::operator[](const int32_t i) {
	if (i >= size) {
		// how to throw the exception here?
	}
	return *(this->data + i);
}

template <typename T>
myvector<T>::myvector(const myvector<T>& other)
    : size { other.size }
    , cap { other.cap }
    , data { new T[size] } {
	for (int i = 0; i < size; i++) {
		this->data[i] = other.data[i];
	}
}

template <typename T>
myvector<T>& myvector<T>::operator=(const myvector<T>& other) {
	if (this != &other) {
		delete[] this->data;
		this->size = other.size;
		this->cap  = other.cap;
		auto temp = new T[size];
		for (int32_t i = 0; i < other.size; i++) {
			temp[i] = other[i]; 
		}
		this->data = temp;
	}
	return *this;
}

template <typename T>
myvector<T>::~myvector() {
	delete[] this->data;
}
