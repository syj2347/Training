# 进行了一些文件内容提取处理的练习（具体为将txt的字符串转化成列表，取出上下行对应元素的差值绝对值再取平均，把结果存入csv文件中）
import os
import pandas as pd
filename = './data'

ans_all = []
for name in sorted(os.listdir(filename)):
    filename1 = os.path.join(filename, name)
    for people in sorted(os.listdir(filename1)):
        filename2 = os.path.join(filename1, people)
        for t in sorted(os.listdir(filename2)):
            ans = []
            filename3 = os.path.join(filename2, t)
            with open(filename3, 'r') as f:
                ls = f.readlines()
                ls = [line.strip() for line in ls]
                for line in ls:
                    tt = line.split(',')
                    ans_i = []
                    for s in tt:
                        ans_i.append(float(s))
                    ans.append(ans_i)
                ans1 = []
                for i in range(1, len(ans)):
                    ans_j = []
                    for j in range(len(ans[i])):
                        ans_j.append(abs(ans[i][j] - ans[i - 1][j]))
                    ans1.append(ans_j)
                ans2 = []
                for j in range(len(ans1[0])):
                    sum = 0.0
                    for i in range(len(ans1)):
                        sum += ans1[i][j]
                    ans2.append(sum / (len(ans1) - 1))
                ans_all.append(ans2)
                print(ans2)
d = pd.DataFrame(ans_all)
d.to_csv('test.csv', index=False, mode='a')
