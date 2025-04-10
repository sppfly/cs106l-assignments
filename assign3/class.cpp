#include "class.h"
#include <cstdint>
#include <initializer_list>

namespace assign3 {

template <typename T>
vector<T>::vector()
    : data(nullptr)
    , size(0)
    , cap(0) {
}

template <typename T>
vector<T>::vector(int32_t size)
    : data { new T[size] }
    , size { size }
    , cap { size } {
}

template <typename T>
vector<T>::vector(std::initializer_list<T> init)
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
vector<T>::~vector() {
	delete[] this->data;
}
}
