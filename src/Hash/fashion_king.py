test_case = int(input())

# 파이썬에서 모두 대문자로 작성하면 const의 의미인가?
for i in range(test_case):
    c_count = int(input())
    bucket = {}
    for j in range(c_count):
        name, tag = list(input().split())
        if tag in bucket:
            bucket[tag].append(name)
        else:
            bucket[tag] = [name]
    cnt = 1
    for i in bucket:
        cnt *= (len(bucket[i]) + 1)
    print(cnt - 1)



