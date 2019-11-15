template <typename T>
int pivot(T[] a, int i, int f) {
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
void quick(T[] a, int i, int f) {
	if (f > i) {
		int p = pivot(a, i, f);
		quick(a, i, p - 1);
		quick(a, p + 1, f);
	}
}
template <typename T>
void quicksort(T[] a, int n) {
	quick(a, 0, n - 1);
}


