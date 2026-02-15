#include<iostream>
#include<memory>
#include<functional>
#include<atomic>
using namespace std;

template<class T>
class SmartPtr
{
public:
	// RAII
	// ⼀种利⽤对象⽣命周期来管理获取到的动态资源，避免资源泄漏
	SmartPtr(T* ptr)
		:_ptr(ptr)
	{ }

	~SmartPtr()
	{
		cout << "delete []:" << _ptr << endl;
		delete[] _ptr;
	}

	T& operator*()
	{
		return *_ptr;
	}

	T* operator->()
	{
		return _ptr;
	}

	T& operator[](size_t i)
	{
		return _ptr[i];
	}

private:
	T* _ptr;
};

//int main()
//{
//	SmartPtr<int> sp1 = new int[5]{1,2,3,4,5};
//	*sp1 += 1;
//	sp1[2] += 1;
//
//	SmartPtr<pair<int, int>> sp2 = new pair<int, int>[2];
//	sp2->first = 1;
//	sp2->second = 1;
//
//	return 0;
//}

//double Divide(int a, int b)
//{
//	// 当b == 0时抛出异常
//	if (b == 0)
//	{
//		throw "Divide by zero condition!";
//	}
//	else
//	{
//		return (double)a / (double)b;
//	}
//}
//void Func()
//{
//	SmartPtr<int> sp1 = new int[10];
//	SmartPtr<int> sp2 = new int[10];
//
//	int len, time;
//	cin >> len >> time;
//	cout << Divide(len, time) << endl;
//}
//
//int main()
//{
//	try
//	{
//		Func();
//	}
//	catch (const char* errmsg)
//	{
//		cout << errmsg << endl;
//	}
//	catch (const exception& e)
//	{
//		cout << e.what() << endl;
//	}
//	catch (...)
//	{
//		cout << "未知异常" << endl;
//	}
//
//	return 0;
//}

class A
{
public:
	A(int a1 = 1, int a2 = 1)
		:_a1(a1)
		, _a2(a2)
	{
		cout << "A()" << endl;
	}

	~A()
	{
		cout << "~A()" << endl;
	}

	int _a1 = 1;
	int _a2 = 1;
};
//
//int main()
//{
//	// 拷贝对象存在问题
//	/*SmartPtr<int> sp1 = new int[10];
//	SmartPtr<int> sp2(sp1);*/
//
//	//auto_ptr<A> ap1(new A);
//	//ap1->_a1++;
//
//	// 管理全转移，ap1悬空
//	//auto_ptr<A> ap2(ap1);
//	// ap1->_a1++; // 报错
//	//ap2->_a1++;
//
//	unique_ptr<A> up1(new A);
//	// 不允许拷贝
//	// unique_ptr<A> up2(up1);
//	//unique_ptr<A> up2(move(up1)); // 可以移动
//	up1->_a1++;
//
//	up1.release();
//
//	//if (up1)
//	if (up1.operator bool())
//	{
//		cout << "up1不为空" << endl;
//	}
//	else
//	{
//		cout << "up1为空" << endl;
//	}
//
//	shared_ptr<A> sp1(new A);
//	// 支持拷贝
//	shared_ptr<A> sp2(sp1);
//	sp1->_a1++;
//
//	return 0;
//}


namespace bit
{
	template<class T>
	class shared_ptr
	{
	public:
		explicit shared_ptr(T* ptr = nullptr)
			:_ptr(ptr)
			//, _pcount(new int(1))
			, _pcount(new atomic<int>(1))
		{
		}

		// RAII
		template<class D>
		explicit shared_ptr(T* ptr, D del)
			:_ptr(ptr)
			, _pcount(new int(1))
			, _del(del)
		{
		}

		shared_ptr(const shared_ptr& sp)
			:_ptr(sp._ptr)
			, _pcount(sp._pcount)
		{
			++(*_pcount);
		}


		~shared_ptr()
		{
			// 引用计数减到0，说明最后一个管理智能指针对象，要释放资源
			release();
		}

		void release()
		{
			if (--(*_pcount) == 0)
			{
				//cout << "delete []:" << _ptr << endl;
				//delete _ptr;
				_del(_ptr);

				delete _pcount;
			}
		}

		shared_ptr& operator=(const shared_ptr& sp)
		{
			if (_ptr != sp._ptr)
			{
				release();
				_ptr = sp._ptr;
				_pcount = sp._pcount;
				++(*_pcount);
			}
			return *this;
		}

		T* get() const
		{
			return _ptr;
		}

		int use_count()
		{
			return *_pcount;
		}

		T& operator*()
		{
			return *_ptr;
		}

		T* operator->()
		{
			return _ptr;
		}

		T& operator[](size_t i)
		{
			return _ptr[i];
		}

	private:
		T* _ptr;
		//int* _pcount; // 引用计数
		atomic<int>* _pcount;

		function<void(T*)> _del = [](T* ptr) {delete ptr; };
	};

	template<class T>
	class weak_ptr
	{
	public:
		weak_ptr()
		{
		}

		weak_ptr(const shared_ptr<T>& sp)
			:_ptr(sp.get())
		{
		}

		// 不参与资源的管理

	private:
		T* _ptr = nullptr;
		// int* _pcount;
	};
}

//int main()
//{
//	bit::shared_ptr<A> sp1(new A);
//	bit::shared_ptr<A> sp2(sp1);
//	sp1 = sp1;
//	sp1 = sp2;
//
//	bit::shared_ptr<A> sp3(new A);
//
//	sp1 = sp3;
//}


//template<class T>
//void DeleteArrayFunc(T* ptr)
//{
//	delete[] ptr;
//}
//
//template<class T>
//class DeleteArray
//{
//public:
//	void operator()(T* ptr)
//	{
//		delete[] ptr;
//	}
//};
//
//int main()
//{
//	// 定制删除器
//	bit::shared_ptr<A> sp1(new A[10], DeleteArray<A>()); // 仿函数
//	bit::shared_ptr<A> sp2(new A[10], DeleteArrayFunc<A>); // 函数指针
//
//	// 推荐
//	bit::shared_ptr<A> sp3(new A[10], [](A* ptr) {delete[] ptr; }); //  lambda
//	bit::shared_ptr<FILE> sp4(fopen("Test.cpp", "r"), [](FILE* ptr) {fclose(ptr); });
//	bit::shared_ptr<A> sp5(new A);
//
//
//	// 删除器的位置是不一致的，shared_ptr在构造函数参数，unique_ptr类模板的参数
//	std::unique_ptr<A, DeleteArray<A>> up1(new A[10]);  //仿函数
//	std::unique_ptr<A, void(*)(A*)> up2(new A[10], DeleteArrayFunc<A>);  //函数指针
//	auto del = [](A* ptr) {delete[] ptr; };
//	std::unique_ptr<A, decltype(del)> up3(new A[10], del);  //lambda
//
//	// 更简洁的方式
//	std::shared_ptr<A[]> sp10(new A[10]);
//	std::unique_ptr<A[]> up10(new A[10]);
//
//	auto sp11 = make_shared<A>(1, 1);
//
//	return 0;
//}


//struct ListNode
//{
//	int _data;
//	/*bit::shared_ptr<ListNode> _next;
//	bit::shared_ptr<ListNode> _prev;*/
//	bit::weak_ptr<ListNode> _next;
//	bit::weak_ptr<ListNode> _prev;
//	//ListNode* _next;
//	//ListNode* _prve;
//
//	~ListNode()
//	{
//		cout << "~ListNode()" << endl;
//	}
//};
//
//int main()
//{
//	// 循环引用 -> 内存泄漏
//	bit::shared_ptr<ListNode> n1(new ListNode);
//	bit::shared_ptr<ListNode> n2(new ListNode);
//	cout << n1.use_count() << endl;
//	cout << n2.use_count() << endl;
//
//	n1->_next = n2;
//	n2->_prev = n1;
//
//	cout << n1.use_count() << endl;
//	cout << n2.use_count() << endl;
//
//	return 0;
//}
//
//int main()
//{
//	std::shared_ptr<string> sp1(new string("111111"));
//	std::shared_ptr<string> sp2(sp1);
//
//	std::weak_ptr<string> wp = sp1;
//	cout << wp.expired() << endl;
//	cout << wp.use_count() << endl << endl;
//
//	// sp1和sp2都指向了其他资源，则weak_ptr就过期了
//	sp1 = make_shared<string>("222222");
//	cout << wp.expired() << endl;
//	cout << wp.use_count() << endl << endl;
//	
//	// 没有过期，通过lock拷贝一个shared_ptr对象来访问资源
//	if(!wp.expired())
//	{
//		auto sp = wp.lock();
//		cout << wp.expired() << endl;
//		cout << wp.use_count() << endl << endl;
//		*sp += "xxxxxxxx";
//	}
//
//	sp2 = make_shared<string>("333333");
//	cout << wp.expired() << endl;
//	cout << wp.use_count() << endl << endl;
//
//	return 0;
//}