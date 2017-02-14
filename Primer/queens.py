
blocks = {}
counter = 0
[n, k] = map(int, str(input()).split())

def path(x, y, dx, dy, blocks):

    sub_cnt = 0
    
    print(x, y, dx, dy)
    while (x >= 1 and 
           x <= n and 
           y >= 1 and 
           y <= n and 
           x*n + y not in blocks
           ):
        sub_cnt += 1
        x += dx
        y += dy 
    
    print(sub_cnt)
    return sub_cnt

[x, y] = map(int, str(input()).split())

for i in range(k):
    [a, b] = map(int, str(input()).split())
    blocks[a*n + b] = 1
    
arr_dir = [
    [-1, 0],
    [-1, -1],
    [0, -1],
    [1, -1],
    [1, 0],
    [1, 1],
    [0, 1],
    [-1, 1]
]

print(blocks)
for [dx, dy] in arr_dir:
    counter += path(x+dx, y+dy, dx, dy, blocks)
    
print(counter)