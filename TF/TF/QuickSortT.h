#include <vector>
using namespace std;
template <typename T>
int pivotMenToMay(vector<T>& a, int i, int f) {
	T piv = a[i]; int izq = i + 1; int der = f;
	while (der >= izq) {
		if (a[izq] <= piv) ++izq;
		else if (a[der] >= piv) --der;
		else {
			T t = a[der];
			a[der--] = a[izq];
			a[izq++] = t;
		}
	}
	if (der != i) {
		T t = a[der];
		a[der] = a[i];
		a[i] = t;
	}
	return der;
}
template <typename T>
void quickMenToMay(vector<T>& a, int i, int f) {
	if (f > i) {
		int p = pivotMenToMay(a, i, f);
		quickMenToMay(a, i, p - 1);
		quickMenToMay(a, p + 1, f);
	}
}
template <typename T>
void quicksortMenToMay(vector<T>& a, int n) {
	quickMenToMay(a, 0, n - 1);
}


template <typename T>
int pivotMayToMen(vector<T>& a, int i, int f) {
	T piv = a[i]; int izq = i + 1; int der = f;
	while (der >= izq) {
		if (a[izq] >= piv) ++izq;
		else if (a[der] <= piv) --der;
		else {
			T t = a[der];
			a[der--] = a[izq];
			a[izq++] = t;
		}
	}
	if (der != i) {
		T t = a[der];
		a[der] = a[i];
		a[i] = t;
	}
	return der;
}
template <typename T>
void quickMayToMen(vector<T>&a, int i, int f) {
	if (f > i) {
		int p = pivotMayToMen(a, i, f);
		quickMayToMen(a, i, p - 1);
		quickMayToMen(a, p + 1, f);
	}
}
template <typename T>
void quicksortMayToMen(vector<T>& a, int n) {
	quickMayToMen(a, 0, n - 1);
}

