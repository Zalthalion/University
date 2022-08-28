def reVal(num): 
    
    if num >= 0 and num <= 9:
        return chr(num + ord('0'))
    elif num >= 10 and num <= 35:
        return chr(num - 10 + ord('A'))
    else:
        return chr(num-36 + ord('a'))

def fromDeci(res, base, inputNum): 
	while (inputNum > 0):
		res+= reVal(inputNum % base)
		inputNum = int(inputNum / base)
	res = res[::-1]
	return res

def deciToAny(number, base):
    '''Function that takes the given number as string and converts it
        from decimal number base to the given base''' 

    a = ("0","1","2","3","4","5","6","7","8","9")
    b = a + ("A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z")
    c = b + ('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z')
    numberDecimal = 0
    
    numLen = len(number)-1
    for letter in number:
        numberDecimal = numberDecimal + (c.index(letter) * base**numLen)
        numLen+=-1

    return numberDecimal

def is_polydivisible(number, base):
    '''Function, that checks if the given number n is a polydivisable number in the given base'''
    

    i = 0
    j = int(len(str(number)))
    isPoly = True
    while i < j:
        
        if deciToAny(number, base) % int(len(str(number))) != 0:
            isPoly = False
            return isPoly
        
        
        number = number[:-1]
        i += 1

    return isPoly

def get_polydivisible(nth, base):
    if nth == 0:
        return 0
    i = 0
    pollyCounter = 0
    while pollyCounter < nth:
        temp = fromDeci("",base,i)
        if is_polydivisible(temp, base) == True:
            pollyCounter+=1
        
        i+=1
    if temp == "":
        return "0"
    return temp


# print(is_polydivisible("1232", 10))
# print(is_polydivisible("123220", 10))
# print(is_polydivisible("123220", 6))

# print(get_polydivisible(22, 10))
# print(get_polydivisible(42, 16))
