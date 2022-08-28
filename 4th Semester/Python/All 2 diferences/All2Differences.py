
# from tqdm import tqdm
# ## Second attempt ###
# ### O(n^2) was the best i could do ###
# ### Passed all tests on codewars ###
# def twos_difference(lst):
#     result = [] 
#     if len(lst) == 0:
#         return lst
#     for first in tqdm(lst):
#             if first+2 in lst:
#                 result.append((first, first+2))
#     result.sort()
#     return result

# #My patience let it work untill 10^5

def twos_difference(lst):
    list = set(lst)
    return sorted((element, element + 2) for element in lst if element + 2 in list)

test = list(range(1, 1_000_000_000)) 

prints = twos_difference(test)

print(prints)

