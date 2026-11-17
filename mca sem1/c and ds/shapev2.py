
user = int(input())

vertical = []
horizontal = []

for i in range(user):
    x1, y1, x2, y2 = map(int, input().split())

    if x1 == x2:
        vertical.append([x1, min(y1, y2), max(y1, y2)])
    else:
        horizontal.append([y1, min(x1, x2), max(x1, x2)])


count = 0

for i in range(len(vertical)):
    for j in range(i + 1, len(vertical)):

        x1 = min(vertical[i][0], vertical[j][0])
        x2 = max(vertical[i][0], vertical[j][0])

        for a in range(len(horizontal)):
            for b in range(a + 1, len(horizontal)):

                y1 = min(horizontal[a][0], horizontal[b][0])
                y2 = max(horizontal[a][0], horizontal[b][0])

                # Check vertical lines
                left = (vertical[i][1] <= y1 and vertical[i][2] >= y2)
                right = (vertical[j][1] <= y1 and vertical[j][2] >= y2)

                # Check horizontal lines
                bottom = (horizontal[a][1] <= x1 and horizontal[a][2] >= x2)
                top = (horizontal[b][1] <= x1 and horizontal[b][2] >= x2)

                if left and right and top and bottom:
                    count += 1

print(count)
