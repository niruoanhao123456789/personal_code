print("在python中字符串用单引号或者双引号都行")
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