#pragma once
template <class T>
class PerfArray {
public:
	PerfArray();
	PerfArray(unsigned int _MAX_SIZE);
	void add(T obj);
	void remove(unsigned int index);
	int getSize();
	T operator[](unsigned int index);
	void operator+=(T obj);
	void clean();
private:
	const int DEFAULT_MAX_SIZE = 10000;
	int MAX_SIZE;
	T* array;
	int size;
};

//DEFAULT CONSTRUCTOR
template <class T>
PerfArray<T>::PerfArray() {
	MAX_SIZE = DEFAULT_MAX_SIZE;
	array = new T[MAX_SIZE];
	size = 0;
}

//CONSTRUCTOR W/ SIZE
template <class T>
PerfArray<T>::PerfArray(unsigned int _MAX_SIZE) {
	MAX_SIZE = _MAX_SIZE;
	array = new T[MAX_SIZE];
	size = 0;
}

//OPERATOR []
template<class T>
T PerfArray<T>::operator[](unsigned int index) {
	return array[index];
}

//OPERATOR +=
template<class T>
void PerfArray<T>::operator+=(T obj) {
	array[size] = obj;
	size++;
}

//ADD
template <class T>
void PerfArray<T>::add(T obj) {
	array[size] = obj;
	size++;
}

//random note use peel back method****

//CLEAN
template <class T>
void PerfArray<T>::clean() {
	

}

//REMOVE
template <class T>
void PerfArray<T>::remove(unsigned int index) {

	size <= 1 ? size = 0 : size--;
	array[index] = array[size];
}

//GET SIZE
template <class T>
int PerfArray<T>::getSize() {
	return size;
}