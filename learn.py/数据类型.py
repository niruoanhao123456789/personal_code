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

print('在python中,bool类型的真假为True,False;在Java和C++中为true,false；其值也是真为1,假为0;所以整型能与bool类型相加')
e = True
f = False
print(type(e))
print(type(f))

print("在python中字符串用单引号或者双引号都行,因为python没有字符类型,只有字符串类型")
c = 'hello world'
print(type(c))
d = 'this is "python string"'
print(d)
print('在python里,如果字符串里有英语的双引号,该字符串可以用单引号表示;反之亦然')
print('如果字符串里既有单引号又有双引号,可将字符串用三引号表示\n')
e = ''''it' is "python string"'''
f = """'it' is "python string" """
print(e)
print(f)

print('字符串f长度为',len(f))

a = 'hello '
b = 'world'
print(a+b)
print('python中允许字符串相加来进行拼接,拼接的结果是生成一个新的字符串,对原有字符串是没有影响的')
print('但不允许字符串与数值之间进行拼接')

print('在python中 int默认为4个字节,可动态扩容;float固定为8个字节;bool为一个字节;字符串是变长的')
print('不同类型能进行的操作也不同\n')

print('动态类型指程序运行中,变量类型可能发生改变')
a1 = 10
print(type(a1))

a1 = 'hello'
print(type(a1))

a1 = True
print(type(a1))

print('静态类型指程序运行中,变量类型不会发生改变,如Java,C++里的类型')
print('是否为静态类型,取决于程序运行时,类型是否改变;而不是定义变量时是否声明类型')
print('像python在定义变量时也可以声明类型,但不影响其为动态类型')

# 在python中要指定变量类型应 变量名:类型 这种方式
a:int = 1