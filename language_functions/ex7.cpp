template< typename T>
class unique_handle{
	using ptr = typename T::pointer;
	ptr value;
public:
	unique_handle(unique_handle const&) = delete;
	unique_handle& operator=(unique_handle const &) = delete;
	explicit unique_handle
};

int main(){

	return 0;
}
