#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>


using namespace std;
using namespace literals;

//void Print(int n, int i)
//{
//	while (i < n)
//	{
//		// this_thread命名空间
//		// 获取本线程id
//		cout << this_thread::get_id() << ":" << i++ << endl;
//	}
//	cout << endl;
//}
//
//int main()
//{
//	thread t1(Print, 10, 0);
//	thread t2(Print, 20, 10);
//
//	if(t1.joinable())
//		t1.join(); 
//	if(t2.joinable())
//		t2.join();
//
//	cout << this_thread::get_id() << endl;
//
//	return 0;
//}


// mutex
//void Print(int n, int& rx, mutex& rmtx)
//{
//	rmtx.lock();
//	for (int i = 0;i < n;i++)
//	{
//		++rx;
//	}
//	rmtx.unlock();
//}
//
//int main()
//{
//	int x = 0;
//	mutex lock;
//	thread t1(Print, 1000000, ref(x), ref(lock));
//	thread t2(Print, 2000000, ref(x), ref(lock));
//
//	if (t1.joinable())
//		t1.join(); 
//	if(t2.joinable())
//		t2.join();
//
//	cout << x << endl;
//
//	return 0;
//}


// time_mutex跟mutex完全类似，只是额外提供try_lock_for和try_lock_untile的接⼝，这两个接⼝
// 跟try_lock类似，只是他不会⻢上返回，⽽是直接进⼊阻塞，直到时间条件到了或者解锁了就会唤醒试图获取锁资源
//timed_mutex tmtx;
//
//void fireworks(int i)
//{
//	while (!tmtx.try_lock_for(1000ms))
//	{
//		cout << "-";
//	}
//
//	cout << i;
//	this_thread::sleep_for(5000ms);
//	cout << "*\n";
//	tmtx.unlock();
//}
//
//int main()
//{
//	thread threads[2];
//	for (int i = 0;i < 2;i++)
//	{
//		threads[i] = thread(fireworks, i);
//	}
//
//	for (auto& th : threads)
//	{
//		if (th.joinable())
//			th.join();
//	}
//
//	return 0;
//}


// lock_guard ⽀持RAII⽅式管理互斥锁资源的类
// 可以在构造的时候通过传参adopt_lock_t的adopt_lock对象管理已经lock的锁对象。其次lock_guard类不⽀持拷⻉构造
//int main()
//{
//	int x = 0;
//	mutex mtx;
//	auto Print = [&](size_t n) {
//		lock_guard<mutex> lock(mtx);
//
//		for (int i = 0;i < n;i++)
//			++x;
//		};
//
//	thread t1(Print, 1000000);
//	thread t2(Print, 2000000);
//
//	if (t1.joinable())
//		t1.join();
//	if (t2.joinable())
//		t2.join();
//
//	cout << x << endl;
//
//	return 0;
//}


// lock是⼀个函数模板，可以⽀持对多个锁对象同时锁定，如果其中⼀个锁对象没有锁住，
// lock函会把已经锁定的对象解锁⽽进⼊阻塞，直到锁定所有的所有的对象。
//
//mutex foo, bar;
//
//void task_a()
//{
//	// foo.lock() bar.lock() 的功能可以为下面的功能
//	lock(foo, bar);
//	cout << "task_a" << endl;
//	foo.unlock();
//	bar.unlock();
//}
//
//void task_b()
//{
//	lock(bar, foo);
//	cout << "task_b" << endl;
//	bar.unlock();
//	foo.unlock();
//}
//
//int main()
//{
//	foo.lock();
//
//	thread th1(task_a);
//	thread th2(task_b);
//
//	cout << "xxxxxx" << endl;
//	bar.lock();
//	foo.unlock();
//
//	cout << "yyyyyy" << endl;
//	bar.unlock();
//
//	if (th1.joinable())
//		th1.join();
//	if (th2.joinable())
//		th2.join();
//
//	return 0;
//}


// try_lock也是⼀个函数模板，尝试对多个锁对象进⾏同时尝试锁定，如果全部锁对象都锁定了，返
// 回 - 1，如果某⼀个锁对象尝试锁定失败，把已经锁定成功的锁对象解锁，并则返回这个对象的下标（第⼀个参数对象，下标从1开始算）
//
//std::mutex foo, bar;
//void task_a() {
//	foo.lock();
//	std::cout << "task a\n";
//	bar.lock();
//	// ...
//	foo.unlock();
//	bar.unlock();
//} 
//
//void task_b() {
//	int x = try_lock(bar, foo);
//	if (x == -1) {
//		std::cout << "task b\n";
//		// ...
//		bar.unlock();
//		foo.unlock();
//	}
//	else{
//		std::cout << "[task b failed: mutex " << (x ? "foo" : "bar") << " locked]\n";
//	}
//}
//
//int main()
//{
//	std::thread th1(task_a);
//	std::thread th2(task_b);
//	th1.join();
//	th2.join();
//	return 0;
//}


//call_once 多线程执⾏时，让第⼀个线程执⾏Fn⼀次，其他线程不再执⾏Fn
//int winner;
//
//void set_winner(int x) { winner = x; }
//	std::once_flag winner_flag;
//
//void wait_1000ms(int id) {
//	// count to 1000, waiting 1ms between increments:
//	for (int i = 0; i < 1000; ++i)
//		std::this_thread::sleep_for(std::chrono::milliseconds(1));
//	// claim to be the winner (only the first such call is executed):
//	std::call_once(winner_flag, set_winner, id);
//}
//
//int main()
//{
//	std::thread threads[10];
//	// spawn 10 threads:
//	for (int i = 0; i < 10; ++i)
//		threads[i] = std::thread(wait_1000ms, i + 1);
//	std::cout << "waiting for the first among 10 threads to count 1000 ms...\n";
//	for (auto& th : threads)
//		th.join();
//	std::cout << "winner thread: " << winner << '\n';
//
//	return 0;
//}


// atomic是⼀个模板的实例化和全特化均定义的原⼦类型，他可以保证对⼀个原⼦对象的操作是线程安全的。
// atomic对T类型的要求模板可⽤任何满⾜可复制构造(CopyConstructible) 及可复制赋值(CopyAssignable) 的可平凡复制(TriviallyCopyable) 类型 T 实例化，
// T类型⽤以下⼏个函数判断时，如果⼀个返回false，则⽤于atomic不是原⼦操作。

// condition_variable需要配合互斥锁系列进⾏使⽤，主要提供wait和notify系统接⼝。
// wait需要传递⼀个unique_lock<mutex>类型的互斥锁，wait会阻塞当前线程直到被notify。
// 在进⼊阻塞的⼀瞬间，会解开互斥锁，⽅便其他线程获取锁，访问条件变量。当被notify唤醒时，他会同时获取到锁，再继续往下运⾏。
// notify_one会唤醒当前条件变量上等待的其中⼀个线程，使⽤时他也需要⽤互斥锁保护，如果没有
// 现成阻塞等待，他啥事都不做；notify_all会唤醒当前条件变量上等待的所有线程线程。
// condition_variable_any 类是 std::condition_variable 的泛化。相对于只在
// std::unique_lock<std::mutex> 上⼯作的 std::condition_variable，condition_variable_any 能在任何满⾜可基本锁定(BasicLockable) 要求的锁上⼯作