
template<typename T>
class MyVector {
public:
	// 기본 생성자
	MyVector()
		: data_(nullptr),
		capacity_(3),
		size_(0)
	{
		data_ = new T[capacity_];
	}

	// 복사 생성자
	MyVector(const MyVector& other)
		: capacity_(other.capacity_),
		size_(other.size_)
	{
		// 메모리 할당
		data_ = new T[capacity_];

		// 배열의 원소 복사
		std::copy(other.data_, other.data_ + other.size_, data_);
	}

	// 복사 대입 연산자
	MyVector& operator=(const MyVector& other) {
		capacity_ = other.capacity_;
		size_ = other.size_;
		// 기존의 메모리 해제
		delete[] data_;

		// 메모리 새로 할당
		data_ = new T[capacity_];

		// 배열의 원소 복사
		std::copy(other.data_, other.data_ + other.size_, data_);
	}

	// 이동 생성자
	MyVector(MyVector&& other) noexcept // 예외를 던지지 않음!
		: capacity_(other.capacity_),
		size_(other.size_),
		data_(other.data_)
	{
		other.data_ = nullptr;
		other.size_ = 0;
		other.capacity_ = 0;
	}

	// 이동 대입 연산자
	MyVector& operator=(MyVector&& other) noexcept {
		capacity_ = other.capacity_;
		size_ = other.size_;
		// 기존 메모리 해제
		delete[] data_;
		data_ = other.data_;

		other.data_ = nullptr;
		other.size_ = 0;
		other.capacity_ = 0;
	}

	// {1, 2, 3, 4} 로 생성 가능하게 함
	MyVector(std::initializer_list<T> il)
		: size_(il.size()),
		capacity_(il.size() * 2),
		data_(nullptr)
	{
		data_ = new T[capacity_];
		std::copy(il.begin(), il.end(), data_);
	}

	// 소멸자
	~MyVector() {
		// 메모리 해제
		delete[] data_;
	}

	// 원소 복사 삽입
	void push_back(const T& data) {
		increase_if_needed();

		data_[size_] = data;
		size_ += 1;
	}

	// 원소 생성 삽입
	// Perfect forwarding
	template<typename... T>
	void emplace_back(T&&... args) {
		increase_if_needed();

		data_[size_] = T(std::forward<T>(args)...);
		size_ += 1;
	}

	// 하나 제거(흉내만)
	void pop_back() {
		if (size_ > 0) {
			size_ -= 1;
		}
	}

	// 현재 배열의 크기 반환
	std::size_t size() const {
		return size_;
	}

	// 원소 접근
	// non-const lvalue 객체만 호출 가능
	T& operator[](std::size_t index)& {
		return data_[index];
	}

	// 원소 접근
	// lvalue 객체만 호출 가능
	const T& operator[](std::size_t index) const& {
		return data_[index];
	}

	// 원소 접근
	// non-const rvalue 객체만 호출 가능
	T&& operator[](std::size_t index)&& {
		return std::move(data_[index]);
	}

	// 처음을 의미하는 iterator 반환
	T* begin() {
		return data_;
	}

	const T* begin() const {
		return data_;
	}


	// 끝을 의미하는 iterator 반환
	T* end() {
		return data_ + size_;
	}

	const T* end() const {
		return data_ + size_;
	}

private:
	void increase_if_needed() {
		if (size_ >= capacity_) {
			// 용량 늘리기
			capacity_ = capacity_ * 2;

			// 메모리 새로 할당
			T* new_data = new T[capacity_];

			// 기존 데이터 복사
			std::copy(data_, data_ + size_, new_data);

			// 기존 메모리 해제
			delete[] data_;

			// 기존 포인터 대체
			data_ = new_data;
		}
	}

	T* data_;
	std::size_t capacity_;
	std::size_t size_;
};