#while exp:
#循环体

# 打印1 - 10
# i = 1
# while i <= 10:
#     print(i)
#     i = i + 1

# 求1-100的和
# i = 1
# sum = 0
# while i <= 100:
#     sum+=i
#     i+=1
# print(f"sum = {sum}")

# 求n!
# n = int(input("n = "))
# i = 1
# fac = 1
# while i <= n:
#     fac *= i
#     i += 1
# print(f"fac = {fac}")

# 求1!+2!+3!+……+n!
# n = int(input("n = "))
# i = 1
# sum = 0
# while i <= n:
#     j = 1
#     factorResult = 1
#     while j <= i:
#         factorResult *= j
#         j += 1
#     sum += factorResult
#     i += 1
# print(f"sum = {sum}")


# for
# for 循环变量 in 迭代对象:

#打印1 - 10
# for i in range(1,11):
#     print(i)

#range(begin,end,step)为内建函数,其作用为提供迭代对象,数据范围为[begin,end),步长默认为1

#打印1 - 10里的偶数
# for i in range(1,12,2):
#     print(i)

#在Pycharm里可以用shift + F6针对光标所在的变量统一进行重命名

#按顺序打印10-1
# for i in range(1,11,1):
#     print(i)


#continue 和 break

# for i in range(1,11):
#     if i == 3:
#         continue
#     print(i)

#求平均数，但有多少个数字暂定
# Sum = 0
# count = 0
# while True:
#     i = input("输入一个数（输入;为停止输入）:")
#     if i == ';':
#         break
#     Sum += float(i)
#     count += 1
# print(f"平均数为:{Sum/count}")