__author__ = 'Kalyan'

# Score you will get if you pass all the tests.
max_marks = 25

problem1_notes = '''

A magic number is a number which results in 1 when the following process is done.

1. replace number with sum of squares of each digit in the same base
2. repeat till you get a single digit

If result is 1, then it is a magic number, else it is not.
e.g. 28  is a magic number in base 10.
28 -> 68 ( 4 + 64) -> 100 (36 + 64) -> 1

12 is not a magic number in base 10
12 -> 5 ( 1 + 4)

12 is not a magic number is base 5
22 (12 in base 10 is 22 in base 5)
-> 13 (8 in base 5 is 13)
-> 20 (10 is base 5 is 20) ->
-> 4 (single digit and it is not 1, so not a magic number).

Your job for this question is to write a function that will return the a list of
1st K magic numbers in base 8 in ascending order.

Use python builtins and data structures to solve this problem.

Mock test hint: use the debugger or pytutor if you get stuck :).

Notes:
1. k < 0 should raise ValueError.
'''

def get_oct_magic_numbers(k):
    pass
    if k<0:
        raise ValueError
    result=[]
    i=1
    while len(result) != k:
        if magic_number(int(oct(i)[1:])) == 1:
            result.append(int(i))
        i=i+1
    return result

def magic_number(k):
    if k==1:
        return 1
    recur_set=set()

    while(True) and (k not in recur_set):
        recur_set.add(k)
        sum=0
        number=[int(i) for i in str(k)]
        if len(number)>1:
            for i in number:
                sum=sum+i*i
            if sum==1:
                return 1
            else:
                k=int(oct(sum)[1:])
    return -1

# some basic tests given, write more according to given constraints. atleast check that
# you can generate 10 magic numbers
def test_get_oct_magic_numbers():
    assert [1, 8] == get_oct_magic_numbers(2)
    assert [1, 8, 18, 27, 64, 76, 77, 97, 105, 130] == get_oct_magic_numbers(10)

