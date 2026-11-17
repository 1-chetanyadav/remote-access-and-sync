def apply_gravity1(dice):
	rows =len(dice)
    cols =len(dice[0])
    
    for col in range(cols):
    	stone = 0
    for row in range(rows):
    	if dice[row][col] =='*';
        	stones += 1
 return dice
 def r_rotate(dice):
 	row = len(dice)
    col = len(dice[0])
    
    new_dice = []
    for cols in range(cols):
    	for rows in range(rows -1,-1,-1):
    		new_row.append(box[rows][cols])
 		new_dice.append(new_row)
return new_dice

 def l_rotate(dice):
 	row = len(dice)
    col = len(dice[0])
    
    new_dice = []
    for cols in range(cols):
    	for rows in range(rows -1,-1,-1):
    		new_row.append(dice[rows][cols])
 		new_dice.append(new_row)
return new_dice

m,n=map(int,input(),split())

dice = apply_gravity(dice)

for i in range(l):
	direction = input().strip().lower
    
    if direction == "right":
    	dice = r_rotate(dice)
        
    elif direction == "left":
    	dice = l_rotate(dice)
    dice=apply_gravity(dice)
for row in dice:
print("".join))
        
    