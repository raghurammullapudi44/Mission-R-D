__author__ = 'Kalyan'

notes = '''
Implement a left binary search and write exhaustive tests for the same. Left binary search returns the left most
element when a search key repeats. For e.g if input is [1,2,3,3,4,4,5] and I search 3, it should return 2 as index 2 is
the left most occurance of 3.

In [1,1,1,1,1,1,1,1], I search for 1, you should return 0.

Note that we are looking for a binary search => we want not more than log(N) lookups, so a solution that involves finding
a random 1 and then doing a linear scan to the left is not a solution :).
'''

def left_binary_search(input, value):
    pass
    if input:
        if input[0] == value:
            print "key is present in iterable"
            return 0
        else:
            try:
                low, high = 0, len(input)
                mid = (low + high)/2
                answer=None
                while low <= high:
                    if input[mid] == value:
                        answer=mid
                        high =mid - 1
                    elif input[mid] > value:
                        high = mid - 1
                    else:
                        low = mid+1

                    mid = (low + high)/2
                if answer:
                    print "key is present in iterable"
                    return answer
                else:
                    print "key is not present in iterable"
            except IndexError:
                print "key is not present in iterable"
                assert True
    else:
        print "iterable  is None"

    return -1

# write your own exhaustive tests :)
def test_left_binary_search_student():
    pass
    assert 2 == left_binary_search([1,2,3,3,4,4,5], 3)
    assert 0 == left_binary_search([1,1,1,1,1,1,1,1], 1)
    assert 1 == left_binary_search([0,1,1,1,1,1,1,1], 1)
    assert 0 == left_binary_search([0,0,0,1,1,1,1,1], 0)
    assert 9 == left_binary_search([1,2,3,3,4,4,4,4,5,6,6,6,6,7,8],6)
    assert 0 == left_binary_search([1,1,1,1,2,2,2,2,3,3,3,3,3,4,4,4,4],1)
    assert 0 == left_binary_search([1,1,1,1,2,2,2,2,3,3,3,3,3,4,4,4,4],1)
    assert 4 == left_binary_search([1,1,1,1,2,2,2,2,3,3,3,3,3,4,4,4,4],2)
    assert 8 == left_binary_search([1,1,1,1,2,2,2,2,3,3,3,3,3,4,4,4,4],3)
    assert 13 == left_binary_search([1,1,1,1,2,2,2,2,3,3,3,3,3,4,4,4,4],4)
    assert -1 == left_binary_search([1,1,1,1,2,2,2,2,3,3,3,3,3,4,4,4,4],0)
    input = range(10)
    for index, value in enumerate(input):
        assert index == left_binary_search(input, value)
    assert -1 == left_binary_search(input, -10)
    assert -1 == left_binary_search(input, 100)
    assert -1 == left_binary_search(range(10), -10)
    assert -1 == left_binary_search(range(100), 100)
    assert -1 == left_binary_search([], 10)
    assert -1 == left_binary_search(None, 10)
    assert 0 == left_binary_search([10], 10)
    assert 0 == left_binary_search([10,10], 10)
    assert -1 == left_binary_search([10], 5)
    assert -1 == left_binary_search([10], 12)

# these tests run only on our runs and will be skipped on your computers.
# DO NOT EDIT.
import pytest
def test_left_binary_search_server():
    servertests = pytest.importorskip("unit6_server_tests")
    servertests.test_left_binary_search(left_binary_search)
