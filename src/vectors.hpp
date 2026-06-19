template<typename T, int S>
class Vector {
public:
	T& operator[](int i) {
		return vector[i];
	}
protected:
	T vector[S];
};
