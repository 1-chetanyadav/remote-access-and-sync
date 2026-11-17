import math
def inter_section(a, b):
    x1, y1, x2, y2 = a
    x3, y3, x4, y4 = b

    dx1 = x2 - x1
    dy1 = y2 - y1
    dx2 = x4 - x3
    dy2 = y4 - y3

    cross = dx1 * dy2 - dy1 * dx2
    if abs(cross) < 0.000001:
        return None

    t = ((x3 - x1) * dy2 - (y3 - y1) * dx2) / cross
    u = ((x3 - x1) * dy1 - (y3 - y1) * dx1) / cross

    if 0 <= t <= 1 and 0 <= u <= 1:
        x = round(x1 + t * dx1, 2)
        y = round(y1 + t * dy1, 2)
        return (x, y)
    return None

def distance(a, b):
    return math.sqrt((a[0] - b[0]) ** 2 +
                     (a[1] - b[1]) ** 2)

def find_shape(graph):
    visited = set()
    path = []

    def dfs(current, parent):
        visited.add(current)
        path.append(current)

        for next_point in graph[current]:

            if next_point == parent:
                continue
            if next_point in path:
                index = path.index(next_point)
                return path[index:]

            if next_point not in visited:
                result = dfs(next_point, current)

                if result:
                    return result

        path.pop()
        return None

    for point in graph:
        if point not in visited:
            result = dfs(point, None)

            if result:
                return result

    return None


def calculate_area(shape):
    area = 0
    perimeter = 0

    for i in range(len(shape)):
        a = shape[i]
        b = shape[(i + 1) % len(shape)]

        area += a[0] * b[1] - b[0] * a[1]
        perimeter += distance(a, b)

    return abs(area) / 2, perimeter
n = int(input())
sticks = []
for i in range(n):
    x1, y1, x2, y2 = map(int, input().split())
    sticks.append((x1, y1, x2, y2))
total_length = 0

for stick in sticks:
    total_length += distance(
        (stick[0], stick[1]),
        (stick[2], stick[3])
    )
points = []

for i in range(n):
    line_points = [
        (sticks[i][0], sticks[i][1]),
        (sticks[i][2], sticks[i][3])
    ]
    for j in range(n):
        if i != j:
            point = inter_section(sticks[i], sticks[j])

            if point is not None and point not in line_points:
                line_points.append(point)

    x1, y1, x2, y2 = sticks[i]

    if abs(x2 - x1) >= abs(y2 - y1):
        line_points.sort(key=lambda p: p[0], reverse=(x2 < x1))
    else:
        line_points.sort(key=lambda p: p[1], reverse=(y2 < y1))

    points.append(line_points)

graph = {}

for line in points:
    for i in range(len(line) - 1):
        a = line[i]
        b = line[i + 1]

        if a not in graph:
            graph[a] = []

        if b not in graph:
            graph[b] = []

        if b not in graph[a]:
            graph[a].append(b)

        if a not in graph[b]:
            graph[b].append(a)

shape = find_shape(graph)

if shape is None:
    print("Abandoned")

else:
    player_area, used_length = calculate_area(shape)
    remaining_length = total_length - used_length

    computer_area = remaining_length ** 2 / (4 * math.pi)
    if player_area >= computer_area:
        print("Kalyan")
    else:
        print("Computer")