from collections import Counter
n = int(input().strip())
birds = [int(height_temp) for height_temp in input().strip().split(' ')]
print (Counter(birds).most_common()[0][0])
