a, b = map(int, input().strip().split())
temp = str(a + b)

ans = []
for i in temp:
    ans.append(i)

flag = 0
if ans[0] == '-':
    flag = 1
    ans.pop(0)
ans.reverse() 
    
i = 0
cnt = 0
while i < len(ans):
    if cnt % 3 == 0 and cnt != 0:
        ans.insert(i, ',')
        i += 1
    i += 1
    cnt += 1

ans.reverse()
if flag:
    ans.insert(0, '-')
print("".join(ans))
