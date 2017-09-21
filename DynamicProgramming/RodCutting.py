# -*- coding:utf-8 -*

price = [1,5,8,9,10,17,17,20,24,30]
def recurCutRod(length):
    if length == 0:
        return 0
    revenue = 0
    i = 0
    while i < length:
        revenue = max(q, price[i]+recurCutRod(length-i))
    return revenue

print recurCutRod(2)
