#include <initializer_list>
#include <iostream>
#include <array>

namespace la {
	template<typename T, int R, int C>
	class Matrix {
	public:
		Matrix() = default;
		Matrix(T value) {
			for (auto& row : data) {
				row.fill(value);
			}
		}
		Matrix(std::initializer_list<std::initializer_list<T>> matrix) {
			int r = 0;
			for (auto& row : matrix) {
				int c = 0;
				for (auto& value : row) {
					data[r][c] = value;
					c++;
				}
				r++;
			}
		}
		
		auto& operator[](size_t i) {
			return data[i];
		}
		const auto& operator[](size_t i) const {
			return data[i];
		}
		friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
			for (auto& row : matrix.data) {
				for (auto& value : row) {
					os << value << ' ';
				}
				os << '\n';
			}
			return os;
		}
		
	private:
		std::array<std::array<T, C>, R> data{};
	};
	
	template<typename T>
	using Matrix2x2 = Matrix<T, 2, 2>;
	template<typename T>
	using Matrix3x3 = Matrix<T, 3, 3>;
	template<typename T>
	using Matrix4x4 = Matrix<T, 4, 4>;
	template<typename T, int N>
	using MatrixNxN = Matrix<T, N, N>;
	
	template<typename T, int N>
	using RowVector = Matrix<T, 1, N>;
	template<typename T, int N>
	using ColumnVector = Matrix<T, N, 1>;
}
