# [BOJ-Silver4] 1764_듣보잡
n, m = map(int, input().split())

data1 = set()  #듣
data2 = set()  #보

for _ in range(n):
  data1.add(input())
for _ in range(m):
  data2.add(input())

result = sorted(set(data1 & data2))  # 교집합

print(len(result))
for i in result:
  print(i)