from collections import Counter

n,m = map(int, input().split())

dud = []
for _ in range(n):
    dud.extend(map(str,input().split()))
    
bo =  []
for _ in range(m):
    bo.extend(map(str,input().split()))
dud.extend(bo)    
dudbo = dud
count = Counter(dudbo)
duplicate_count = sum(1 for value in count.values() if value > 1)
duplicates = [item for item, freq in count.items() if freq > 1]

print(duplicate_count)
for i in range(duplicate_count):
    print(duplicates[i])