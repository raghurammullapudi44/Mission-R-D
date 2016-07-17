__author__ = 'Kalyan'

# Score you will get if you pass all the tests.
max_marks = 25

problem_notes = '''
Find the Lowest common multiple of 2 positive numbers which are given in their prime factorized form defined in problem1

You must return the result in a valid prime factorized form as described in problem1.
Invalid results will fail the tests, so do pay attention to the definition of a valid factorization given in problem1.

Use python builtins and data types as you see fit.

For HCF and LCM: http://www.whitman.edu/mathematics/higher_math_online/section03.06.html

Notes:
1. Assume inputs are valid and of the the right type.
2. first and second are list of tuples which represent a number and they are in prime factorized form as described in
   problem1
'''
from mocktest_problem1 import *

def get_lcm(first, second):
    pass
    '''if len(first)>=1:
        x=1
        for i in first:
            x=x*i[0]**i[1]
    else:
        return second
    if len(second)>=1:
        y=1
        for i in second:
            y=y*i[0]**i[1]
    else:
        return first

    if x>y:
        greater=x
    else:
        greater=y

    while(True):
        if((greater % x == 0) and (greater % y == 0)):
            lcm = greater
            break
        greater += 1'''
    lcm=find_lcm(first,second)
    return factorize_number(lcm)

def find_lcm(first,second):
    a=dict(first)
    b=dict(second)
    lcm=1
    for i in a.keys():
        if i in b.keys():
            lcm=lcm*i**max(a[i],b[i])
            a.pop(i)
            b.pop(i)
        else:
            lcm=lcm*i**a[i]
            a.pop(i)
    for i in b.keys():
        lcm=lcm*i**b[i]
        b.pop(i)
    return lcm

# some basic tests given, write more according to given constraints.
def test_get_lcm():
    assert [(2,1), (5,1)] == get_lcm([(2,1)], [(5,1)])
    assert [(3,2)] == get_lcm([], [(3,2)]) # empty list is 1
    assert [(2, 2), (3, 1), (5, 2), (7, 2), (17, 2)] == get_lcm([(2, 1), (5, 2), (7, 2)], [(2, 2), (3, 1), (17, 2)])
    assert [(2, 2), (17, 1), (19, 1), (2687, 4), (7919, 4)] == get_lcm([(2, 1), (19, 1), (7919, 4)], [(2, 2), (17, 1), (2687, 4)])