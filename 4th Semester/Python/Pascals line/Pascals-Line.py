import math
from tqdm import tqdm

class PascallTriangle:
    triangle = []
    def __init__(self, linesCount):  
        for count in range(linesCount): 
            
            row = [] 
            for element in range(count + 1): 
            
                row.append(combination(count, element))
            self.triangle.append(row)

    def easyline(self, rowNR):
        sum = 0
        row = self.triangle[rowNR]
        for i in range(0, len(row)):
            
            sum += row[i]**2
        return int(sum)

    def easyDiagonal(self, diagonal, line):
        sum = 0
        for i in range(diagonal, line):
            rinda = self.triangle[i]
            sum += rinda[diagonal]
            
        return int(sum)




def combination(n, r): # correct calculation of combinations, n choose k
    return int((math.factorial(n)) / ((math.factorial(r)) * math.factorial(n - r)))



PT = PascallTriangle(10)
    
# pascals_triangle(8)
for row in PT.triangle:
    print(row)
print(PT.easyline(4))
print(PT.easyDiagonal(0,8))


#Only check half of the triengle
#Second diagonal is every 7th number
#First diagonal and last is always 1 so no point in checking thos
#Mention the memory to sound smart
#Mention O(n) to sound smart
#i think thats all the special ocasions 
#went from 10^9 to 5 * 10^8 atleast
#problem is the factorial

# for i in tqdm(range(1, 1_000_000)):
#     math.factorial(i)

from PIL import Image,ImageDraw

# # Create empty black canvas
# im = Image.new('RGB', (255, 255))

# # Draw red and yellow triangles on it and save
# draw = ImageDraw.Draw(im)
# draw.polygon([(20,10), (200, 200), (100,100)], fill = (255,0,0))
# draw.polygon([(200,10), (200, 200), (150,50)], fill = 'yellow')

# im.save('test.png')
