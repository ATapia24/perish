#ifndef PERFARRAY_H
#define PERFARRAY_H

template <class T>
class PerfArray {
public:
	PerfArray();
	PerfArray(unsigned int _MAX_SIZE);
	void add(T obj);
	void remove(unsigned int index);
	void remove();
	int size();
	T operator[](unsigned int index);
	void operator+=(T obj);
	void clean();
	void update();
	void killAll();
	void spawnAll();
private:
	const int DEFAULT_MAX_SIZE = 10000;
	int MAX_SIZE;
	T* array;
	int _size;
};

//DEFAULT CONSTRUCTOR
template <class T>
PerfArray<T>::PerfArray() {
	MAX_SIZE = DEFAULT_MAX_SIZE;
	array = new T[MAX_SIZE];
	_size = 0;
}

//CONSTRUCTOR W/ SIZE
template <class T>
PerfArray<T>::PerfArray(unsigned int _MAX_SIZE) {
	MAX_SIZE = _MAX_SIZE;
	array = new T[MAX_SIZE];
	_size = 0;
}

//OPERATOR []
template<class T>
T PerfArray<T>::operator[](unsigned int index) {
	return array[index];
}

//OPERATOR +=
template<class T>
void PerfArray<T>::operator+=(T obj) {
	array[_size] = obj;
	_size++;
}

//ADD
template <class T>
void PerfArray<T>::add(T obj) {
	array[_size] = obj;
	_size++;
}

//random note use peel back method****

//CLEAN
template <class T>
void PerfArray<T>::clean() {
	

}

//REMOVE w/ INDEX
template <class T>
void PerfArray<T>::remove(unsigned int index) {

	_size <= 1 ? _size = 0 : _size--;
	array[index] = array[_size];
}

//REMOVE
template <class T>
void PerfArray<T>::remove() {
	for (int i = 0; i < _size; i++) {
		array[i]->kill();
	}

	_size = 0;
}

//GET SIZE
template <class T>
int PerfArray<T>::size() {
	return _size;
}

//UPDATE OBJECTS
template <class T>
void PerfArray<T>::update() {
	for (int i = 0; i < _size; i++)
		array[i]->update();
}

//KILL ALL
template <class T>
void PerfArray<T>::killAll() {
	for (int i = 0; i < _size; i++)
		array[i]->kill();
}

//SPAWN ALL
template <class T>
void PerfArray<T>::spawnAll() {
	for (int i = 0; i < _size; i++)
		array[i]->spawn();
}

#endif