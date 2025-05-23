print('python中变量的命名规则,命名规范和使用和C语言中的一样')
a = 10
b = 20
tmp = a
a = b
b = tmp
print('a = ',a,'b = ',b)
print('对a的第一个等号是对其进行初始化,后面的等号是赋值操作')

print('数据类型种类,与C相似\n')

c= 10
print(type(c))
print('a的类型规定是通过给其初始化的值来确定的,和C语言在定义变量时要声明数据类型不同\n')
print('在Python中int数据范围是"无穷"的,其内存可以根据赋值数据的大小来自动扩容,所以Python没有short,long long\n')

d = 0.5
print(d)
print(type(d))
print('Python中float是双精度的,相当于C++/Java里的double')
print('\nPython设计哲学：解决问题只提供一种方案\n')