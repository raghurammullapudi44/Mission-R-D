__author__ = 'Kalyan'

notes = '''
Fill up each of this methods so that it does what it is intended to do. Use
only the standard data types we have seen so far and builtin functions.

Do not use any control flow statements (if, for...) in this assignment.
Assume that inputs are valid and of expected type, so no checking required.

builtin functions: http://docs.python.org/2/library/functions.html
use constants from string module (string.XXXX) as required.

Notes:
1. Last assignment was about declarative thinking in terms of available utility functions.
   This assignment is about thinking in terms of python builtin  data types - numbers, strings, sets,
   dicts and tuples.

2. Start thinking in terms of converting one datatype to another based on what you need. Think
   in terms of set and list operations where required instead of thinking in terms of for loops and while loops.
   You need both kinds of thinking to write good code.

3. All the methods will require 1-3 lines of straight line code.

4. These methods are are meant to help you think in certain ways, some of them can be done more efficiently without
   using the data types but that is not the goal of this assignment.

Use the console to experiment and figure out the solution.

Reading material
 http://stackoverflow.com/questions/3489071/in-python-when-to-use-a-dictionary-list-or-set
 https://docs.python.org/2/library/stdtypes.html#set-types-set-frozenset
 https://docs.python.org/2/library/stdtypes.html#mapping-types-dict
 It is a good idea to review the lessons as well!
'''

from placeholders import *

import string

def get_lower_to_upper_dict():
    """
    returns a dict which contains a mapping from lower case letters to upper case letters
    Hint: see the constants in the string module, and the zip builtin function
    """
    return dict(zip("abcdefghijklmnopqrstuvwxyz",list("ABCDEFGHIJKLMNOPQRSTUVWXYZ")))
    #keys="abcdefghijklmnopqrstuvwxyz"
    #values="ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    #return dict(zip(keys,list(values)))


def test_lower_to_upper_dict():
    lower_to_upper = get_lower_to_upper_dict()
    assert 26 == len(lower_to_upper)
    for x in lower_to_upper:
        y = lower_to_upper[x]
        assert 1 == len(x)
        assert x.islower()
        assert 1 == len(y)
        assert y.isupper()
        assert x.upper() == y


def get_encoding_dict():
    """
    returns a dict which maps a -> 1, b -> 2 ... z->26 and A -> 1, B ->2 ... Z->26
    No control flow allowed.
    """
    return dict(zip("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ",range(1,27)+range(1,27)))
    #keys="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
    #values=range(1,27)+range(1,27)
    #return dict(zip(keys,values))

def test_get_encoding_dict():
    d = get_encoding_dict()
    assert len(d) == 52
    for key in d:
        assert ord(key.lower()) - ord('a') + 1 == d[key]

def get_vowels(input):
    """
    returns the set of vowels in the input string, case is not important.
    e.g Apple and apple both return set(['a', 'e'])

    No control flow plz.
    """
    return set(['a', 'i', 'e', 'u', 'o'])&set(input.lower())

def test_get_vowels():
    assert set([]) == get_vowels("fly")
    assert set(['a', 'e']) == get_vowels("APPLE")
    assert set(['a', 'e']) == get_vowels("apple")
    assert set(['a', 'e', 'i', 'o', 'u']) == get_vowels(string.ascii_letters)


def bit_count_even(number):
    """
    Returns True if the binary representation of number (>=0) has even number of 1s.
    E.g 5 (101) returns True, 6 (110) returns True,  7 (111) returns False.

    Hint: sum of bits is even. use builtins and list.
    """
   # return (sum(map(int,list((bin(number)[2:])))) in range(0,100,2))
    return (sum(map(int,bin(number)[2:]))%2 == 0)

def test_bit_count_even():
    assert True == bit_count_even(0xFF)
    assert False == bit_count_even(0xFE)
    assert True == bit_count_even(0)
    assert False == bit_count_even(8)
