#链接：https://www.nowcoder.com/questionTerminal/bac5a2372e204b2ab04cc437db76dc4f
#来源：牛客网
# test git


n, k= list(map(int,input().split()))
if k == 0:
    ans = n * n  # k=0是比较特殊的
else:
    ans = 0
    for y in range(k + 1, n + 1):
        # 从每一列来看，根据每y个一个循环的规律，快速计算余数矩阵余数值
        # cycle = [i for i in range(1, y)] + [0]  # 循环部分
        satisfy_num = y - k  # 一个循环中满足的组合个数
        cycle_num = n // y  # 完整循环个数
        res_num = n % y  # 剩余不完整部分循环中的元素个数
        ans += satisfy_num * cycle_num + max(res_num - k + 1, 0)  # 注意这里最差就是不完整部分满足个数为0，但是不能为负数
print(ans)
