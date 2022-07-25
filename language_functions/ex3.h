#include <vector>

template <class T, size_t W, size_t K>
class Array2d{
	typedef T* iterator;
	typedef T const * const_iterator;
	std::vector<T> array;
public:
	Array2d() : array(W*K) {}
	Array2d(std::initializer_list<T> il) : array(il) {}
	constexpr T* data() { return array.data(); }
	constexpr T const * data() const { return array.data(); }
	constexpr T& at(size_t const w, size_t const k);
	constexpr T const & at(size_t const w, size_t const k) const;
	constexpr T& operator()(size_t const w, size_t const k);
	constexpr T const & operator()(size_t const w, size_t const k) const;
	constexpr bool empty() const;
	constexpr size_t size(int const rank) const;
	void fill(T const & value);
	void swap(Array2d & other);
	iterator begin() {return array.data();}
	iterator end() {return array.data() + array.size();}
	const_iterator begin() const {return array.data();}
	const_iterator end() const {return array.data() + array.size();}
};
