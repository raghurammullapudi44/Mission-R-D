__author__ = 'Kalyan'

from placeholders import *

notes = '''
Fill up each of these methods so that it does what it is intended to do. Use
only the standard data types we have seen so far and builtin functions.

Idea is for you to refer to online documentation and get your work done.

All of these functions require use of the builtin functions documented at
http://docs.python.org/2/library/functions.html

Your job is to see which ones apply and invoke them. Most of the methods require
writing 1 or 2 lines of code.

Do not use any control flow statements (if, for...) in this assignment.
Assume that inputs are valid and of expected type, so no checking required.

I repeat, No control statements please even if you already know python!

Notes:

1. This assignment will encourage top-down declarative thinking in you. You are all familiar with bottoms-up thinking,
   this is another important habit to develop. You need both.

2. This will help you to think in terms of problem decomposition into smaller problems which are usually
   done for you by python or you solve the smaller problems further till you reach sub-problems that python does for you.

3. Read the input constraints carefully, I purposely constrain inputs for this learning assignment.

4. If you think a particular builtin will be useful, play with it in the console and see how it works.

5. Reading material:
    http://latentflip.com/imperative-vs-declarative/ (read once before and after doing the exercises).
'''

def get_even_numbers(count):
    """
    Returns a list of 1st 'count' (>=0) even numbers.
    """
    return range(2,(count*2)+1,2) # replace __ with a single call to a builtin funciton.

def test_get_even_numbers():
    assert [] == get_even_numbers(0)
    assert [2,4] == get_even_numbers(2)
    assert [2,4,6,8,10] == get_even_numbers(5)

def ascii_distance(first, second):
    """
    returns the positive distance between the ascii values of input characters
    assume: inputs are valid single letters
    e.g. inputs ("a", "b") should return 1,
        inputs ("b", "a") should return 1 too (postive distance)
    """
    return abs(ord(first)-ord(second)) # use 2 builtin functions to get your work done.

def test_ascii_distance():
    assert 1 == ascii_distance("a", "b")
    assert 1 == ascii_distance("b", "a")
    assert 1 == ascii_distance("B", "A")
    assert 32 == ascii_distance("A", "a")
    assert 31 == ascii_distance("B", "a")

def get_binary(number):
    """
    Return the binary string of number (>=0) without 0b prefix.
    For e.g 5 returns "101", 20 returns "10100" etc.
    """
    return (bin(number)[2:]) # use a builtin and slice the result ...

def test_get_binary():
    assert "100" == get_binary(4)
    assert "11111111" == get_binary(255)
    assert "0" == get_binary(0)

def get_min_max_avg(input):
    """
    Return a tuple of min, max and average of input sequence. assume input is non-empty list of ints and return tuple of ints.
    """
    return (min(input),max(input),sum(input)/len(input)) # replace blanks with calls to 1 or more builtins.

def test_get_min_max_avg():
    assert (0, 9, 4) == get_min_max_avg(range(10))
    assert (0, 0, 0) == get_min_max_avg([0])
    assert (-1, 3, 1) == get_min_max_avg([-1,3,1])


def base36_to_octal(input):
    """
    returns a specified string in base 36 as a string in octal
    Hint: use a couple of builtins to make this happen.
    """
    return oct(int(input,36))

def test_base36_to_octal():
    assert "012" == base36_to_octal("A")
    assert "043" == base36_to_octal("Z")
    assert "044" == base36_to_octal("10")
    assert "0563" == base36_to_octal("AB")


def count_binary_ones(number):
    """
    Returns the number of 1s in the binary representation of number (>=0)
    For e.g 5 returns 2 (101 has 2 1's), 21 returns 3 ("10101")
    """
    # compose 4 builtins to get this done. No control statements plz
    return sum(map(int,list((bin(number)[2:]))))

def test_count_binary_ones():
    assert 8 == count_binary_ones(0xFF)
    assert 0 == count_binary_ones(0)
    assert 3 == count_binary_ones(0b101010)
    assert 4 == count_binary_ones(15)
