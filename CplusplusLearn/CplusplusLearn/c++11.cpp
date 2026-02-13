#include<iostream>
#include<assert.h>
#include<string>
#include<list>
using namespace std;

// 右值引用和移动语句
//
//int main()
//{
//	//initializer_list<int> mylist;
//	//mylist = { 10, 20, 30 };
//	//cout << sizeof(mylist) << endl;
//	//// 这里begin和end返回的值initializer_list对象中存的两个指针
//	//// 这两个指针的值跟i的地址跟接近，说明数组存在栈上
//	//int i = 0;
//	//cout << mylist.begin() << endl;
//	//cout << mylist.end() << endl;
//	//cout << &i << endl;
//
//	//	// 左值：可以取地址
//	//	// 以下的p、b、c、*p、s、s[0]就是常见的左值
//	//	int* p = new int(0);
//	//	int b = 1;
//	//	const int c = b;
//	//	*p = 10;
//	//	string s("11111111111111111111111111111");
//	//	s[0] = 'x'; 
//	//
//	//	cout << &p << endl;
//	//	cout << &b << endl;
//	//	cout << &c << endl;
//	//	cout << &(*p) << endl;
//	//	cout << &s << endl;
//	//	cout << (void*)&s[0] << endl;
//	//
//	//	// 右值：不能取地址
//	//	double x = 1.1, y = 2.2;
//	//	// 以下几个10、x + y、fmin(x, y)、string("11111")都是常见的右值
//	//	10;
//	//	x + y;
//	//	fmin(x, y);
//	//	string("11111");
//	//	
//	//	// 编译报错
//	//	/*cout << &10 << endl;
//	//	cout << &(x+y) << endl;
//	//	cout << &(fmin(x, y)) << endl;
//	//	cout << &string("11111") << endl;*/
//
//	// 左值：可以取地址
//	//	// 以下的p、b、c、*p、s、s[0]就是常见的左值
//	//	int* p = new int(0);
//	//	int b = 1;
//	//	const int c = b;
//	//	*p = 10;
//	//	string s("111111");
//	//	s[0] = 'x';
//	//	double x = 1.1, y = 2.2;
//	//
//	//	// 左值引用给左值取别名
//	//	int& r1 = b;
//	//	int*& r2 = p;
//	//	int& r3 = *p;
//	//	string& r4 = s;
//	//	char& r5 = s[0];
//	//
//	//	// 右值引用给右值取别名
//	//	int&& rr1 = 10;
//	//	double&& rr2 = x + y;
//	//	double&& rr3 = fmin(x, y);
//	//	string&& rr4 = string("11111");
//	//
//	//	// 左值引用不能直接引用右值，但是const左值引用可以引用右值
//	//	const int& rx1 = 10;
//	//	const double& rx2 = x + y;
//	//	const double& rx3 = fmin(x, y);
//	//	const string& rx4 = string("11111");
//	//
//	//	// 右值引用不能直接引用左值，但是右值引用可以引用move(左值)
//	//	int&& rrx1 = move(b);
//	//	int*&& rrx2 = move(p);
//	//	int&& rrx3 = move(*p);
//	//	string&& rrx4 = move(s);
//	//	string&& rrx5 = (string&&)s;
//	//
//	//	// int&& rrrx1 = move(rrx1);
//
//	return 0;
//}

//class A
//{
//public:
//	A()
//	{
//		cout << "A()" << endl;
//	}
//
//	~A()
//	{
//		cout << "~A()" << endl;
//	}
//};
//
//int main()
//{
//	A();
//	A a1;
//	// 延长匿名对象的生命周期
//	const A& ret1 = A();
//	A&& ref2 = A();
//
//	cout << "main end" << endl;
//
//	return 0;
//}

//void f(int& x)
//{
//	std::cout << "左值引用重载 f(" << x << ")\n";
//}
//
//void f(const int& x)
//{
//	std::cout << "到 const 的左值引用重载 f(" << x << ")\n";
//}
//
//void f(int&& x)
//{
//	std::cout << "右值引用重载 f(" << x << ")\n";
//}
//
//int main()
//{
//	f(10);
//	
//	int a = 20;
//	f(a);
//	
//	const int b = 20;
//	f(b);
//		
//	// 右值引用本身的属性是左值
//	int&& x = 1;
//	f(x);			 // 调用 f(int& x)
//	f(std::move(x)); // 调用 f(int&& x)
//
//	return 0;
//}

//namespace bit
//{
//    class string
//    {
//    public:
//        typedef char* iterator;
//        typedef const char* const_iterator;
//
//        iterator begin()
//        {
//            return _str;
//        }
//        iterator end()
//        {
//            return _str + _size;
//        }
//
//        const_iterator begin() const
//        {
//            return _str;
//        }
//
//        const_iterator end() const
//        {
//            return _str + _size;
//        }
//
//        string(const char* str = "")
//            :_size(strlen(str))
//            , _capacity(_size)
//        {
//            cout << "string(char* str)-构造" << endl;
//            _str = new char[_capacity + 1];
//            strcpy(_str, str);
//        }
//
//        void swap(string& s)
//        {
//            ::swap(_str, s._str);
//            ::swap(_size, s._size);
//            ::swap(_capacity, s._capacity);
//        }
//
//        // 拷贝构造
//        string(const string& s)
//        {
//            cout << "string(const string& s) -- 拷贝构造" << endl;
//
//            reserve(s._capacity);
//            for (auto ch : s)
//            {
//                push_back(ch);
//            }
//        }
//
//        // 移动构造
//        string(string&& s)
//        {
//            cout << "string(string&& s) -- 移动构造" << endl;
//            swap(s);
//        }
//
//        string& operator=(const string& s)
//        {
//            cout << "string& operator=(const string& s) -- 拷贝赋值" << endl;
//            if (this != &s)
//            {
//                _str[0] = '\0';
//                _size = 0;
//
//                reserve(s._capacity);
//                for (auto ch : s)
//                {
//                    push_back(ch);
//                }
//            }
//
//            return *this;
//        }
//
//        // 移动赋值
//        string& operator=(string&& s)
//        {
//            cout << "string& operator=(string&& s) -- 移动赋值" << endl;
//            swap(s);
//            return *this;
//        }
//
//        ~string()
//        {
//            //cout << "~string() -- 析构" << endl;
//            delete[] _str;
//            _str = nullptr;
//        }
//
//        char& operator[](size_t pos)
//        {
//            assert(pos < _size);
//            return _str[pos];
//        }
//
//        void reserve(size_t n)
//        {
//            if (n > _capacity)
//            {
//                char* tmp = new char[n + 1];
//                if (_str)
//                {
//                    strcpy(tmp, _str);
//                    delete[] _str;
//                }
//                _str = tmp;
//                _capacity = n;
//            }
//        }
//
//        void push_back(char ch)
//        {
//            if (_size >= _capacity)
//            {
//                size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
//                reserve(newcapacity);
//            }
//
//            _str[_size] = ch;
//            ++_size;
//            _str[_size] = '\0';
//        }
//
//        string& operator+=(char ch)
//        {
//            push_back(ch);
//            return *this;
//        }
//
//        const char* c_str() const
//        {
//            return _str;
//        }
//
//        size_t size() const
//        {
//            return _size;
//        }
//    private:
//        char* _str = nullptr;
//        size_t _size = 0;
//        size_t _capacity = 0;
//    };
//
//    // 传值返回需要拷贝
//    string addStrings(string num1, string num2) {
//        string str;
//        int end1 = num1.size() - 1, end2 = num2.size() - 1;
//        // 进位
//        int next = 0;
//        while (end1 >= 0 || end2 >= 0)
//        {
//            int val1 = end1 >= 0 ? num1[end1--] - '0' : 0;
//            int val2 = end2 >= 0 ? num2[end2--] - '0' : 0;
//            int ret = val1 + val2 + next;
//            next = ret / 10;
//            ret = ret % 10;
//            str += ('0' + ret);
//        }
//        if (next == 1)
//            str += '1';
//        reverse(str.begin(), str.end());
//        cout << &str << endl;
//
//        return str;
//    }
//}
//
//int main()
//{
//    bit::string ret = bit::addStrings("11111", "2222");
//    cout << &ret << endl;
//
//    bit::string ret1;
//    //...
//    ret1 = bit::addStrings("11111", "2222");
//
//    cout << &ret1 << endl;
//
//    return 0;
//}

//int main()
//{
//    list<string> lt;
//    cout << "*************************" << endl;
//
//    string s1("111111111111111111111");
//    lt.push_back(s1);
//    cout << "*************************" << endl;
//
//    lt.push_back(string("22222222222222222222222222222"));
//    cout << "*************************" << endl;
//
//    lt.push_back("3333333333333333333333333333");
//    cout << "*************************" << endl;
//
//    // 左值move本质授予别人转移你数据资源权限，所以要谨慎
//    // s1管理的资源转移到了lt，其本身被置空
//    lt.push_back(move(s1));
//    cout << "*************************" << endl;
//
//    return 0;
//}


// 引用折叠
//
//// 由于引用折叠限定，f1实例化以后总是一个左值引用
//template<class T>
//void f1(T& x)
//{}
//
//// 由于引用折叠限定，f2实例化后可以是左值引用，也可以是右值引用
//template<class T>
//void f2(T&& x)
//{}
//
//int main()
//{
//    // int&& & r = i;
//
//    typedef int& lref;
//    typedef int&& rref;
//
//    int n = 0;
//    // 引用折叠
//    lref& r1 = n; // r1 的类型是 int&
//    lref&& r2 = n; // r2 的类型是 int&
//    rref& r3 = n; // r3 的类型是 int&
//    rref&& r4 = 1; // r4 的类型是 int&&
//
//    // 没有折叠->实例化为void f1(int& x)
//    f1<int>(n);
//    //f1<int>(0); // 报错
//
//    // 折叠->实例化为void f1(int& x)
//    f1<int&>(n);
//    //f1<int&>(0); // 报错
//
//    // 折叠->实例化为void f1(int& x)
//    f1<int&&>(n);
//    //f1<int&&>(0); // 报错
//
//    // 折叠->实例化为void f1(const int& x)
//    f1<const int&>(n);
//    f1<const int&>(0);
//
//    // 折叠->实例化为void f1(const int& x)
//    f1<const int&&>(n);
//    f1<const int&&>(0);
//
//    // 没有折叠->实例化为void f2(int&& x)
//    //f2<int>(n); // 报错
//    f2<int>(0);
//
//    // 折叠->实例化为void f2(int& x)
//    f2<int&>(n);
//    //f2<int&>(0); // 报错
//
//    // 折叠->实例化为void f2(int&& x)
//    //f2<int&&>(n); // 报错
//    f2<int&&>(0);
//
//    return 0;
//}


// 万能引用
// 传左值，实例化出左值引用的Function函数
// 传右值，实例化出右值引用的Function函数
//template<class T>
//void Function(T&& t)
//{
//    int a = 0;
//    T x = a;
//    //x++;
//    cout << &a << endl;
//    cout << &x << endl << endl;
//}
//
//int main()
//{
//    // 10是右值，推导出T为int，模板实例化为void Function(int&& t)
//    Function(10); // 右值
//
//    int a;
//    // a是左值，推导出T为int&，引用折叠，模板实例化为void Function(int& t)
//    Function(a); // 左值
//
//    // std::move(a)是右值，推导出T为int，模板实例化为void Function(int&& t)
//    Function(std::move(a)); // 右值
//
//    const int b = 8;
//    // b是左值，推导出T为const int&，引用折叠，模板实例化为void Function(const int& t)
//    // 所以Function内部会编译报错，x不能++
//    Function(b);
//    
//    // std::move(b)右值，推导出T为const int，模板实例化为void Function(const int&& t)
//    // 所以Function内部会编译报错，x不能++
//    Function(std::move(b)); // const 右值
//
//    return 0;
//}


// 完美转发forward
//void Fun(int& x) { cout << "左值引用" << endl; }
//void Fun(const int& x) { cout << "const 左值引用" << endl; }
//void Fun(int&& x) { cout << "右值引用" << endl; }
//void Fun(const int&& x) { cout << "const 右值引用" << endl; }
//
//// 万能引用
//template<class T>
//void Function(T&& t)
//{
//    Fun(std::forward<T>(t));
//}
//
//int main()
//{
//    // 10是右值，推导出T为int，模板实例化为void Function(int&& t)
//    Function(10); // 右值
//
//    int a;
//    // a是左值，推导出T为int&，引用折叠，模板实例化为void Function(int& t)
//    Function(a); // 左值
//    // std::move(a)是右值，推导出T为int，模板实例化为void Function(int&& t)
//    Function(std::move(a)); // 右值
//
//    const int b = 8;
//    // a是左值，推导出T为const int&，引用折叠，模板实例化为void Function(const int& t)
//    Function(b); // const 左值
//
//    // std::move(b)右值，推导出T为const int，模板实例化为void Function(const int&& t)
//    Function(std::move(b)); // const 右值
//
//    return 0;
//}


// 可变参数模板
// template<class ...Args>
// void fun(Args&&... args)
//
//template <class ...Args>
//void Print(Args&&... args)
//{
//    cout << sizeof...(args) << endl;
//}
//
//// 编译器底层原理还是一样，实例化生成对应参数类型和个数的多个函数
//void Print()
//{
//    cout << 0 << endl;
//}
//
//void Print(int&& x)
//{
//    cout << 1 << endl;
//}
//
//void Print(double& d, string&& s)
//{
//    cout << 2 << endl;
//}
//
//int main()
//{
//    double x = 2.2;
//    Print(); // 包里有0个参数
//    Print(1); // 包里有1个参数
//    Print(x, string("xxxxx")); // 包里有2个参数
//    Print(1.1, string("xxxxx"), x); // 包里有3个参数
//    return 0;
//}

// 编译时递归推导解析参数
//void ShowList()
//{
//    // 编译器时递归的终止条件，参数包是0个时，直接匹配这个函数
//    cout << endl;
//}
//
//template <class T, class ...Args>
//void ShowList(T x, Args... args)
//{
//    cout << x << " ";
//
//    // args是N个参数的参数包
//    // 调用ShowList，参数包的第一个传给x，剩下N-1传给第二个参数包
//    ShowList(args...);
//}
//
//template <class ...Args>
//void Print(Args... args)
//{
//    // 解析参数包，递归推导
//    ShowList(args...);
//}
//
//int main()
//{
//    Print();
//    Print(1);
//    Print(1, string("xxxxx"));
//    Print(1, string("xxxxx"), 2.2);
//
//    return 0;
//}

// 折叠表达式 C++17
//template <class ...Args>
//void Print(Args... args)
//{
//    ((cout << args << " "), ...);
//
//    cout << "\n";
//}
//
//// Print(1, string("xxxxx"), 2.2);
//// 实例化为下面的函数
//void Print(int x, string y, double z)
//{
//    //((cout << args << " "), ...);
//    ((cout << x << " "), (cout << y << " "), (cout << z << " "));
//
//    cout << "\n";
//}
//
//int main()
//{
//    Print();
//    Print(1);
//    Print(1, string("xxxxx"));
//    Print(1, string("xxxxx"), 2.2);
//
//    return 0;
//}


// 默认⽣成的移动构造函数，对于内置类型成员会执⾏逐成员按字节拷⻉，
// ⾃定义类型成员，则需要看这个成员是否实现移动构造，如果实现了就调⽤移动构造，没有实现就调⽤拷⻉构造。
//class Person
//{
//public:
//    Person(const char* name = "张三yyyyyyyyyyyyyyyyyyyyyyyyyy", int age = 18)
//        :_name(name)
//        , _age(age)
//    {}
//
//     //C++11
//    Person(const Person& p) = delete;
//    Person(Person&& p) = default;
// 
//    ~Person()
//    {}
//
//private:
//     //C++98
//     Person(const Person& p);
//    string _name;
//    int _age;
//};
//
//int main()
//{
//    Person s1;
//    // Person s2 = s1;
//    Person s3 = std::move(s1);
//
//    /*Person s4("xxxxxxxxxxxxxxxxxxxxxxx", 1);
//    s4 = std::move(s2);*/
//
//    return 0;
//}


//class Example 
//{
//public:
//    Example(int a, int b)
//        :_x(a)
//        , _y(b)
//    {
//        cout << "目标构造函数\n";
//    }
//
//    Example(int a)
//        : Example(a, 0)
//    {
//        cout << "委托构造函数\n";
//    }
//
//    int _x;
//    int _y;
//};
//
//class Time {
//public:
//    Time(int h, int m)
//        :_hour(h)
//        , _minute(m)
//    {}
//
//    // error C3511: “Time”: 对委托构造函数的调用应仅为成员初始值设定项
//    // error C2437 : “_second”: 已初始化
//    Time(int h, int m, int s)
//        :Time(h, m)
//       // , _second(s)
//    {}
//
//private:
//    int _hour;
//    int _minute;
//    int _second = 0;
//};
//
//int main()
//{
//    Example(1, 2);
//    Example(1);
//
//    return 0;
//}


// class Base {
//    public:
//        Base(int x, double d)
//            :_x(x)
//            , _d(d)
//        {}
//    
//        Base(int x)
//            :_x(x)
//        {}
//    
//        Base(double d)
//            :_x(d)
//        {}
//    
//    protected:
//        int _x = 0;
//        double _d = 0;
//    };
//
//// 传统的派生类实现构造
////class Derived : public Base {
////public:
////    Derived(int x) : Base(x) {}
////    Derived(double d) : Base(d) {}
////    Derived(int x, double d) : Base(x, d) {}
////};
//
//// C++11继承基类的所有构造函数
//class Derived : public Base {
//public:
//    using Base::Base;
//
//    /*protected:
//        int _i = 0;
//        string _s;*/
//};
//
//int main()
//{
//    Derived d1(1);
//    Derived d2(1.1);
//    Derived d3(2, 2.2);
//
//    return 0;
//}


// lambda表达式的格式： [capture-list] (parameters)-> return type { function boby }
// 
// int main()
//{
//    // 一个简单的lambda表达式
//    //auto add1 = [](int x, int y)->int {return x + y; };
//    auto add1 = [](int x, int y){return x + y; };
//    cout << add1(1, 2) << endl;
//
//// 1、捕捉为空也不能省略
//// 2、参数为空可以省略
//// 3、返回值可以省略，可以通过返回对象自动推导
//// 4、函数体不能省略
//    auto func1 = []
//    {
//        cout << "hello bit" << endl;
//        return 0;
//    };
//    func1();
//
//    int a = 0, b = 1;
//    auto swap1 = [](int& x, int& y)
//    {
//        int tmp = x;
//        x = y;
//        y = tmp;
//    };
//    swap1(a, b);
//    cout << a << ":" << b << endl;
//
//    return 0;
//}


//struct Goods
//{
//    string _name; // 名字
//    double _price; // 价格
//    int _evaluate; // 评价
//
//    // ...
//    Goods(const char* str, double price, int evaluate)
//        :_name(str)
//        , _price(price)
//        , _evaluate(evaluate)
//    {}
//};
//
//struct ComparePriceLess
//{
//    bool operator()(const Goods& gl, const Goods& gr)
//    {
//        return gl._price < gr._price;
//    }
//};
//
//struct ComparePriceGreater
//{
//    bool operator()(const Goods& gl, const Goods& gr)
//    {
//        return gl._price > gr._price;
//    }
//};
//
//struct CompareEvaluateLess
//{
//    bool operator()(const Goods& gl, const Goods& gr)
//    {
//        return gl._evaluate < gr._evaluate;
//    }
//};
//
//struct CompareEvaluateGreater
//{
//    bool operator()(const Goods& gl, const Goods& gr)
//    {
//        return gl._evaluate > gr._evaluate;
//    }
//};
//
//int main()
//{
//    vector<Goods> v = { { "苹果", 2.1, 5 }, { "香蕉", 3, 4 }, { "橙子", 2.2, 3}, { "菠萝", 1.5, 4 } };
//
//    // 类似这样的场景，我们实现仿函数对象或者函数指针支持商品中
//    // 不同项的比较，相对还是比较麻烦的，那么这里lambda就很好用了
//  /*  sort(v.begin(), v.end(), ComparePriceLess());
//    sort(v.begin(), v.end(), ComparePriceGreater());
//    sort(v.begin(), v.end(), CompareEvaluateLess());
//    sort(v.begin(), v.end(), CompareEvaluateGreater());*/
//
//    /*auto priceLess = [](const Goods& gl, const Goods& gr)
//    {
//        return gl._price < gr._price;
//    };
//
//    sort(v.begin(), v.end(), priceLess);*/
// 
//    sort(v.begin(), v.end(), [](const Goods& gl, const Goods& gr) {
//            return gl._price < gr._price;
//        });
//
//    sort(v.begin(), v.end(), [](const Goods& gl, const Goods& gr) {
//            return gl._price > gr._price;
//        });
//
//    sort(v.begin(), v.end(), [](const Goods& gl, const Goods& gr) {
//            return gl._evaluate < gr._evaluate;
//        });
//
//    sort(v.begin(), v.end(), [](const Goods& gl, const Goods& gr) {
//            return gl._evaluate > gr._evaluate;
//        });
//
//    return 0;
//}


//int x = 0;
//// lambda 表达式如果定义在全局位置，捕捉列表必须为空
//// 因为全局变量不用捕捉就可以用，没有可被捕捉的变量
//auto func1 = []()
//    {
//        x++;
//    };
//
//class A
//{
//public:
//    void func()
//    {
//        int x = 0, y = 1;
//
//        auto f1 = [=]
//            {
//                _a1++;
//                return x + y + _a1 + _a2;
//            };
//
//        cout << f1() << endl;
//
//        auto f2 = [&]
//            {
//                x++;
//                _a1++;
//                return x + y + _a1 + _a2;
//            };
//
//        cout << f2() << endl;
//
//        // 捕捉this本质是可以访问成员变量
//        auto f3 = [x, this]
//            {
//                _a1++;
//                return x + _a1 + _a2;
//            };
//
//        cout << f3() << endl;
//    }
//
//private:
//    int _a1 = 0;
//    int _a2 = 1;
//};
//
//int main()
//{
//    // 只能用当前lambda局部域捕捉的对象和全局对象
//    // 捕获列表的意义，本质更方便的使用当前局部域的对象
//    int a = 0, b = 1, c = 2, d = 3;
//    //auto func1 = [a, &b] () mutable
//    auto func1 = [a, &b]
//        {
//            // 值捕捉的变量不能修改，引用捕捉的变量可以修改
//            // a++;
//            b++;
//            int ret = a + b;
//            x++;
//            return ret;
//        };
//    cout << func1() << endl;
//
//    // 隐式值捕捉
//    // 用了哪些变量就捕捉哪些变量
//    auto func2 = [=]
//        {
//            int ret = a + b + c;
//            return ret;
//        };
//    cout << func2() << endl;
//
//    // 隐式引用捕捉
//    // 用了哪些变量就捕捉哪些变量
//    auto func3 = [&]
//        {
//            a++;
//            c++;
//            d++;
//        };
//    func3();
//    cout << a << " " << b << " " << c << " " << d << endl;
//
//    // 混合捕捉1
//    auto func4 = [&, a, b]
//        {
//            //a++;
//            //b++;
//            c++;
//            d++;
//            return a + b + c + d;
//        };
//    func4();
//    cout << a << " " << b << " " << c << " " << d << endl;
//
//    /*  class lambda5
//      {
//      public:
//          lambda5(int a_, int& b_)
//              :a(a_)
//              , b(b_)
//          {}
//
//          int operator()(int x)
//          {
//              ++b;
//              return a + b + x;
//          }
//      private:
//          const int a;
//          int& b;
//      };*/
//
//    auto func5 = [a, &b](int x)
//        {
//            ++b;
//            return a + b + x;
//        };
//    // 等价于
//    // lambda5 func5(a, b);
//    func5(1);
//
//    return 0;
//}