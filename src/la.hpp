namespace la {
	template<typename T, int R, int C>
	class Matrix {
	private:
		T matrix[R][C];
	};
	
	template<typename T>
	using Matrix2x2 = Matrix<T, 2, 2>;
	template<typename T>
	using Matrix3x3 = Matrix<T, 3, 3>;
	template<typename T>
	using Matrix4x4 = Matrix<T, 4, 4>;
	template<typename T, int N>
	using MatrixNxN = Matrix<T, N, N>;
	
	template<typename T, int S>
	using RowVector = Matrix<T, S, 1>;
	template<typename T, int S>
	using ColumnVector = Matrix<T, 1, S>;
}
