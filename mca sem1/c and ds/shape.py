
n = int(input())

vertical = []
horizontal = []

for i in range(n):
    x1, y1, x2, y2 = map(int, input().split())

    if x1 == x2:
        vertical.append([x1, min(y1, y2), max(y1, y2)])

    else:
        horizontal.append([y1, min(x1, x2), max(x1, x2)])


count = 0

# Select two vertical lines
for i in range(len(vertical)):
    for j in range(i + 1, len(vertical)):

        x1 = vertical[i][0]
        x2 = vertical[j][0]

        # Select two horizontal lines
        for a in range(len(horizontal)):
            for b in range(a + 1, len(horizontal)):

                y1 = horizontal[a][0]
                y2 = horizontal[b][0]

                # Check vertical sides
                left = False
                right = False

                if vertical[i][1] <= y1 and vertical[i][2] >= y2:
                    left = True

                if vertical[j][1] <= y1 and vertical[j][2] >= y2:
                    right = True

                # Check horizontal sides
                top = False
                bottom = False

                if horizontal[a][1] <= x1 and horizontal[a][2] >= x2:
                    bottom = True

                if horizontal[b][1] <= x1 and horizontal[b][2] >= x2:
                    top = True

                if left and right and top and bottom:
                    count += 1

print(count)
