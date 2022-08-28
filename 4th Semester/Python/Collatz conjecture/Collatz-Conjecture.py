#imports plotly library
import plotly.graph_objects as go
from tqdm import tqdm


def CollatzSteps (number):
    '''A function that returns the step count from the given number for Collatz conjecture to finish'''
    stepCount = 0
    while number != 1:
        if number % 2 == 0:
            number = number / 2
        else:
            number = (3*number)+1
            # number +=1
        stepCount += 1
    return stepCount

#Testing the CollatzSteps method
print("Collatz Steps Test:")
print("27 should have 111 steps, answer: %a" % CollatzSteps(27))
print("12 should have 9 steps, answer: %a" % CollatzSteps(12))
print("19 should have 20 steps, answer: %a" % CollatzSteps(19))
print("6717 should have 261 steps, answer: %a" % CollatzSteps(6171))


# Saddly this method works in O(n^3) time, a faster method shall be discovered in future
def topTenSteps(number):
    '''A function, that returns a dictionary with top 10 highest step counts and numbers from Collatz Conjecture, till given number)'''
    # Creates an empty dictionary
    thisDict = {}

    i = 1
    # Loop to go through every number, till given number is met
    while i <= number:
        
        steps = CollatzSteps(i)
        # If length of the dictionary is less than 10, then we just add the number and its collatz conjecture step count to dictionary
        if len(thisDict) <10:
            thisDict.update({i:steps})
        else:
        # Else we start to check the existing step counts  
            for x in thisDict:
                # And if already existing step count is smaller than new one
                if steps >= thisDict[x]:
                    #Then we remove the smallest step count and add the new one to dictionary
                    thisDict.pop(min(thisDict, key=thisDict.get))
                    thisDict.update({i:steps})
                    break
        i += 1

    return thisDict

#Testing the topTenSteps method
#It should be valid, tested it to 15, seemet to work correctly :D
print("Top 10 Step counts (number : stepCount): ")
print(topTenSteps(18))


#Generates a plot of all collatz conjecture numbers and their step counts till 100k

Number = 1
Numbers = []
Steps = []
while Number < 100000:
    Numbers.append(Number)
    Steps.append(CollatzSteps(Number))
    Number += 1


fig = go.Figure()
fig.add_trace(go.Scatter(
    x=Numbers,
    y=Steps,
    marker=dict(color="crimson", size=3),
    mode="markers",
))


fig.update_layout(title="Collatz Conjecture",
                  xaxis_title="Number",
                  yaxis_title="Steps")

fig.show()