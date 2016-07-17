__author__ = 'Kalyan'

# Score you will get if you pass all the tests.
max_marks = 25

problem_notes = '''
Convert the passed in positive integer number into its prime factorization form.

If number = a1 ^ p1 * a2 ^ p2 ... where a1, a2 are primes and p1, p2 are powers >=1 then we represent that using lists
and tuples in python as [(a1,p1), (a2,p2), ...]

Note that a1 < a2 < ... and p1, p2 etc are all >= 1.

For e.g.
 [(2,1), (5,1)] is the correct prime factorization of 10 as defined above.
 [(5,1), (2,1)] is invalid as the the order is not correct.
 [(2,1), (3,0), (5,1)] is invalid as a prime with power 0 is present in the result.

Notes
0. This problems asks for explicit type checking!
1. Corner case 1 is represented as an empty list: []
2. Non positive numbers should raise a ValueError
3. If the type of number is not int or long raise a TypeError

Write simple brute force code.
'''
def factorize_number(n):
    pass
    if n < 0:
        raise ValueError
    if 'int' != type(n).__name__ and 'long' != type(n).__name__ :
        raise TypeError
    if n==1:
        return []
    else:
        primefac = []
        d = 2
        while d*d <= n:
            while (n % d) == 0:
                primefac.append(d)
                n //= d
            d += 1
        if n > 1:
            primefac.append(n)
    result=[]
    for i in set(primefac):
        result.append((i,primefac.count(i)))
    return sorted(result)

def get_next_prime_factor(n):
    if n % 2 == 0:
        return 2

# some basic tests given, write more according to given constraints.
def test_factorize_number():
    assert [] == factorize_number(1)
    print factorize_number(2L)
    assert [(2, 1), (5, 1)] == factorize_number(10)
    assert [(2,1)] == factorize_number(2)
    assert [(2, 1), (5, 1), (601, 1)] == factorize_number(6010,)
    assert [(2, 1), (7919, 4)] == factorize_number(7865228921869442L,)