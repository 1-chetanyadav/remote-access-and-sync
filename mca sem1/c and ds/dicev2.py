
def apply_gravity(dice):
    rows = len(dice)
    cols = len(dice[0])

    for col in range(cols):
        stones = 0

        # Count stones
        for row in range(rows):
            if dice[row][col] == '*':
                stones += 1

        # Apply gravity
        for row in range(rows - 1, -1, -1):
            if stones > 0:
                dice[row][col] = '*'
                stones -= 1
            else:
                dice[row][col] = '.'

    return dice


def r_rotate(dice):
    rows = len(dice)
    cols = len(dice[0])

    new_dice = []

    for col in range(cols):
        new_row = []

        for row in range(rows - 1, -1, -1):
            new_row.append(dice[row][col])

        new_dice.append(new_row)

    return new_dice


def l_rotate(dice):
    rows = len(dice)
    cols = len(dice[0])

    new_dice = []

    for col in range(cols - 1, -1, -1):
        new_row = []

        for row in range(rows):
            new_row.append(dice[row][col])

        new_dice.append(new_row)

    return new_dice


# Input
m, n = map(int, input().split())

dice = []

for i in range(m):
    row = list(input().strip())
    dice.append(row)

# Initial gravity
dice = apply_gravity(dice)

# Number of rotations
k = int(input())

for i in range(k):
    direction = input().strip().lower()

    if direction == "right":
        dice = r_rotate(dice)

    elif direction == "left":
        dice = l_rotate(dice)

    dice = apply_gravity(dice)

# Output
for row in dice:
    print("".join(row))
