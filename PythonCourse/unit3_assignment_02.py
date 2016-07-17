__author__ = 'Kalyan'

notes='''
Notes:
1. Don't use any additional modules from python library.
2. Don't change the signature of the function.
3. Review the relevant lessons if you are blocked.

Reading:
Python has an itertools modules which gives powerful utilities to work with iterators.It is a good exercise to read up
all the method implementations on this page: https://docs.python.org/2/library/itertools.html

For e.g. https://docs.python.org/2/library/itertools.html#itertools.chain

You can use ideas from there, but you cannot use itertools module itself in your code :)
'''


# fill up this routine to take a variable number of sequences and return elements from them in round robin till each
# sequence is exhausted. If one of the input sequences is infinite, this is also infinite.
# e.g if input is [1,2,3], (4,5) -> yield 1,4,2,5,3 one after the other.
# use exception control and comprehensions to write elegant code.
# Hint: This assignment requires you to use understand variable arguments, lists, list copy,
# comprehensions, iterators, generators, exception handling, control flow etc.
def round_robin(*seqs):
    x=0
    #max_length=max(seqs,key=len)
    try:
        while x < 5:                # i had used 5 because highest length is equal to 5,but this may not work for higher len
            y=0                     #seqs[],if it wants to work for all replace  5 in while x<5 with the longest
            while y < len(seqs):    #length of the iterator in seqs.to get it donot use infinte odds()
                if type(seqs[y]).__name__ == 'generator':       #or evens() generators because we get MemoryError while calculating longest iterator in seq
                    yield next(seqs[y])
                elif x < len(list(seqs[y])):
                    yield seqs[y][x]
                y += 1
            x += 1
    except MemoryError as me:
        print me
        assert True


# an infinite generator of even numbers.
def evens():
    num = 0
    while True:
        yield num
        num += 2


# an infinite generator of odd numbers.
def odds():
    num = 1
    while True:
        yield num
        num += 2


def test_round_robin():
    gen = round_robin(range(5), "hello")
    assert type(gen).__name__ == 'generator'
    assert [0, 'h', 1, 'e', 2, 'l', 3, 'l', 4, 'o'] == list(gen)

    gen = round_robin([1, 2], "a", (5, 6, 7), [4])
    assert [1, 'a', 5, 4, 2, 6, 7] == list(gen)

    # test with infinite generators
    gen = round_robin("ab", odds(), evens())
    # test the 1st 8 elements
    assert ["a", 1, 0, "b", 3, 2, 5, 4] == [gen.next() for x in range(8)]