#ifndef laba17_h
#define laba17_h
#include <iostream>

template <class T> class Set {
private:
	int capacity, s_size;
	T* arr;

public:
	Set() { 
		capacity = 0; 
		s_size = 0; 
	};

	Set(int value) { 
		capacity = 0; 
		s_size = value; 
		arr = new T[value]; 
	};

	Set(const Set& s) {
		capacity = s.capacity;
		s_size = s.s_size;
		arr = new T[s_size];
		for (int i = 0; i < s_size; i++) {
			arr[i] = s.arr[i];
		}
	}

	Set<T>* operator = (Set<T> const& s) {
		capacity = s.capacity;
		s_size = s.s_size;
		for (int i = 0; i < s_size; i++) {
			arr[i] = s.arr[i];
		}
		return this;
	}

	friend std::ostream& operator << (std::ostream& os, const Set<T>& s) {
		for (int i = 0; i < s.capacity; ++i)
			os << s.arr[i] << ' ';
		os << std::endl;
		return os;
	}

	int size() {
		return s_size;
	}

	bool find(const T value) {
		for (int i = 0; i < capacity; i++) {
			if (arr[i] == value) {
				return true;
			}
		}
		return false;
	}

	void sort(T* s, int n) {
		int i = 0, j = n;
		T p = s[n / 2];
		while (i <= j) {
			while (s[i] < p) 
				i++;
			while (s[j] > p) 
				j--;
			if (i <= j) {
				T temp = s[i];
				s[i] = s[j];
				s[j] = temp;
				i++;
				j--;
			}
		}
		if (j > 0)
			sort(s, j);
		if (i < n)
			sort(s + i, n - i);
	}

	void insert(const T value) {
		if (!find(value)) {
			if (capacity == s_size) {
				s_size++;
				arr[capacity++] = value;
				sort(arr, capacity - 1);
			}
			else {
				arr[capacity++] = value;
				sort(arr, capacity - 1);
			}
		}
	}

	Set unions(const Set& s) {
		if (capacity == 0 || s.capacity == 0)
			throw "Empty Set!!!";
		Set<int> n(capacity + s.capacity);
		for (int i = 0; i < capacity; i++) {
			n.insert(arr[i]);
		}
		for (int i = 0; i < s.capacity; i++) {
			n.insert(s.arr[i]);
		}
		return n;
	}
};
#endif /*laba17_h*/