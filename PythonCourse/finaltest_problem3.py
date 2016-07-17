__author__ = 'Kalyan'

max_marks = 20

problem_notes ='''
Write a routine to sort the given list of numbers according to the number
of prime factors it has.

Constraints:
1. 1 and 0 are considered to have 0 factors
2. For negative numbers, the factor count of the corresponding
   positive numbers is considered for sorting
3. Numbers with more factors come before numbers with fewer factors
4. In case of a tie, bigger numbers (numerically) comes first

Notes:
1. Write additional helper routines as required.
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
    return primefac

# assume is numbers is a valid list of numbers
def sort_by_factor_count(numbers):
    pass
    d=dict()
    for i in numbers:
        d[i]=len(set(factorize_number(abs(i))))
    x=sorted(d.items(), key=sort_key,reverse=True)
    y=[i[0] for i in x]
    return y

def sort_key(item):
    return item[1],item[0]

# one basic test given, write more exhaustive tests
def test_sort_by_factor_count():
    # 10 has 2 factors [2,5] , 6 has 2 [2,3], 8 has 1 [2] and 2 has 1 [2], hence the result
    assert [10,6, 8, 1] == sort_by_factor_count([1, 8, 6, 10])
    assert [6,-10,8,1] == sort_by_factor_count([1, 8, 6, -10])

