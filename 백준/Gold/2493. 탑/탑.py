
n = int(input())
in_top = list(map(int, input().split()))

stack = []

for (i,t) in enumerate(in_top, start=1):
    while stack != []:
        if stack[-1][0] > t:
            print(stack[-1][1],end=' ')
            break
        stack.pop()
    if stack == []:
        print("0",end=' ')
    stack.append((t,i))


