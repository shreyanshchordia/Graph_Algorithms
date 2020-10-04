#!/usr/bin/python
    
N, I = map(int, raw_input().strip().split())
assert 1 <= N <= 10**5
assert 1 <= I <= 10**6
lis_of_sets = []
    
for i in range(I):
    a,b = map(int, raw_input().strip().split())
    assert 0 <= a < N and 0 <= b < N
    indices = []
    new_set = set()
    set_len = len(lis_of_sets)
    s = 0
    while s < set_len:
        if a in lis_of_sets[s] or b in lis_of_sets[s]:
            indices.append(s)
            new_set = new_set.union(lis_of_sets[s])
            del lis_of_sets[s]
            set_len -= 1
        else:
            s += 1
    
    new_set = new_set.union([a, b])
    
    lis_of_sets.append(new_set)
    
answer = N*(N-1)/2
for i in lis_of_sets:
    answer -= len(i)*(len(i)-1)/2
    
print answer
