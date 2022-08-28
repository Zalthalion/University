#Dirty way in 754 chars
def infect_apple(apple, n):
    if(n == 0): 
        return apple
    i = 0
    tempApple = list(map(list, apple))
    while i<n:
        for a in range(0, len(apple)):
            for v in range(0, len(apple[a])):
                if apple[a][v] == 'V':
                    if(a-1 >= 0):
                        tempApple[a-1][v] = 'V'
                        
                    if(a+1 < len(apple)):
                        tempApple[a+1][v] = 'V'
                        
                    if(v-1 >= 0):
                        tempApple[a][v-1] = 'V'
                        
                    if(v+1 < len(apple[a])):
                        tempApple[a][v+1] = 'V'
                        
        i+=1
        apple = list(map(list, tempApple))
  
    return tempApple

apple=[
["A","A","A","A","A"],
["V","A","A","A","A"],
["A","A","A","A","A"],
["A","A","A","A","A"],
["A","A","A","A","A"]
]


infect_apple(apple, 2)



