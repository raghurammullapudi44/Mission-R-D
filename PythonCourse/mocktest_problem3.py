__author__ = 'Kalyan'

# Score you will get if you pass all the tests.
max_marks = 25

problem1_notes = '''
Find the highest common factor of 2 positive numbers which are given in their prime factorized form defined in problem1

You must return the result in a valid prime factorized form as described in problem1.
Invalid results will fail the tests, so do pay attention to the definition of a valid factorization given in problem1.

Use python builtins and datatypes as you see fit.

For HCF and LCM: http://www.whitman.edu/mathematics/higher_math_online/section03.06.html

Notes:
1. Assume inputs are valid and of the the right type.
2. first and second are list of tuples which represent a number and they are in prime factorized form as described in
   problem1

'''
def factorize_number(number):
    if(number>1):
        i = 2
        factors = []
        while i * i <= number:
             if number % i:
                i += 1
             else:
                number //= i
                factors.append(i)
        if number > 1:
            factors.append(number)
        a=set(factors)
        ans=[]
        b=list(a)
        b.sort()
        for i in b:
            ans.append((i,factors.count(i)))
        return ans
    else:
        return []


def hcf(no1,no2):
    while no1!=no2:
        if no1>no2:
            no1-=no2
        elif no2>no1:
            no2-=no1
    return no1


def get_hcf(first, second):
    num1=1
    for i in first:
        a,b= i
        num1=pow(a,b) * num1
    num2=1
    for i in second:
        a,b= i
        num2=pow(a,b) * num2
    res=hcf(num1,num2)
    return factorize_number(res)



# some basic tests given, write more according to given constraints.
def test_get_hcf():
    # hcf of 2 and 5 is 1
    assert [] == get_hcf([(2, 1)], [(5, 1)])
    # hcf of 4 and 6 is 2
    assert [(2, 1)] == get_hcf([(2, 2)], [(2, 1), (3, 1)])
    assert [(2, 1), (3, 1), (5, 1)] == get_hcf([(2, 1), (3, 1), (5, 1), (41, 1)], [(2, 1), (3, 1), (5, 1), (97, 1)])
    print get_hcf([(2, 1), (19, 1), (7919, 4)], [(2, 2), (17, 1), (2687, 4)])
    assert [(2, 1),(19,1)] == get_hcf([(2, 1), (19, 1), (7919, 4)], [(2, 2), (17, 1), (2687, 4)])
    assert [] == get_hcf([], [(2, 5)])
