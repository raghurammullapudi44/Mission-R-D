__author__ = 'Kalyan'

notes = '''
Now we move on to writing both the function and the tests yourself.

In this assignment you have to write both the tests and the code. We will verify your code against our own tests
after you submit.
'''

# fill up this routine to test if the 2 given words given are anagrams of each other. http://en.wikipedia.org/wiki/Anagram
# your code should handle
#  - None inputs
#  - Case  (e.g Tip and Pit are anagrams)
def are_anagrams(first, second):
    pass
    if first != None and second != None:
        common_anagram=[]
        for word in first,second:
            common_anagram.append(''.join(sorted(word.lower())))
        return (len(set(common_anagram))== 1)
    else:
        return False



# write your own exhaustive tests based on the spec given
def test_are_anagrams_student():
    assert True == are_anagrams("pit", "tip") #sample test.
    assert True == are_anagrams("Tip", "Pit")
    assert False == are_anagrams(None, None)
    assert False == are_anagrams("CaT", None)
    assert False == are_anagrams(None, "CaT")
    assert True == are_anagrams("CaT", "TAC")
    assert True == are_anagrams("cat", "act")
    assert False == are_anagrams("cat", "tazzzzzzzzzz")
    assert True == are_anagrams("", "")
    assert False == are_anagrams("a", "")

# these tests run only on our runs and will be skipped on your computers.
# DO NOT EDIT.
import pytest
def test_are_anagrams_server():
    servertests = pytest.importorskip("unit6_server_tests")
    servertests.test_are_anagrams(are_anagrams)
