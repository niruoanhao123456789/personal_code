# 通过控制台来输入输出数据

num1 = input("请输入一个数字：")
print(f"您的刚刚输入的数据为：{num1}")
print(type(num1))
# input的返回值是个字符串,如果只是单纯输出用户输入值可采用上面的方式,
# 如果要将用户输入的值用来计算,需先手动进行类型转化 类型()

a = input('a = ')
b = input('b = ')
a = int(a)
b = int(b)
print(f'a+b = {a+b}')

