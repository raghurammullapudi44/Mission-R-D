__author__ = 'Kalyan'

notes = '''
Though it might appear as if the given tests should be able to catch all logical bugs in de_dup_and_sort, that is not the
case as the code below shows.

So be clear that some blackbox tests alone are no substitute for reasoning/taking care of the correctness yourself.

Now add a test that fails with the given code.
'''

import pytest

def de_dup_and_sort(input):
    """
    Given an input list of strings, return a list in which the duplicates are removed and the items are sorted.
    """
    if input!=None:
        input.sort(key=lambda x:x.lower())

        x=1
        y=1
        while x in range(len(input)):
            if input[x].lower() != input[x-1].lower():
                input[y] = input[x]
                y += 1
            x += 1

        input=input[:y]
        input.sort()
        return input



# add an test input that fails with above code and then fix the above code.
def test_de_dup_and_sort_student():
    pass
    assert None == de_dup_and_sort(None)
    assert ['E','a','b','c','d'] == de_dup_and_sort(['a','b','c','d','A','B','c','d','E'])
    assert ['E', 'F', 'a', 'b', 'c', 'd'] == de_dup_and_sort(['a','b','c','d','A','B','c','d','E','E','F','F','a','b','f','F'])
    assert ['A', 'B', 'W'] == de_dup_and_sort(['W','A','B','a','w'])

def test_de_dup_and_sort():
    assert ["a", "b"] == de_dup_and_sort(["b", "a", "b", "a"])
    assert ["a"] == de_dup_and_sort(["a", "a", "a"])
    assert [] == de_dup_and_sort([])
    assert ["a", "b"] == de_dup_and_sort(["a", "b"])
    assert ["a", "b"] == de_dup_and_sort(["a", "b"]*10)


# this will run only on our runs and will be skipped on your computers.
# DO NOT EDIT
import pytest
def test_de_dup_and_sort_server():
    servertests  = pytest.importorskip("unit6_server_tests")
    servertests.test_de_dup_and_sort(de_dup_and_sort)
