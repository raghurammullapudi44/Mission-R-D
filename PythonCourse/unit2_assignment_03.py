__author__ = 'Kalyan'

notes = '''
Write your own implementation of converting a number to a given base. It is important to have a good logical
and code understanding of this.

Till now, we were glossing over error checking, for this function do proper error checking and raise exceptions
as appropriate.

Reading material:
    http://courses.cs.vt.edu/~cs1104/number_conversion/convexp.html
'''


def convert(number, base):
    """
    Convert the given number into a string in the given base. valid base is 2 <= base <= 36
    raise exceptions similar to how int("XX", YY) does (play in the console to find what errors it raises).
    Handle negative numbers just like bin and oct do.
    """
    #pass
    if 'str'==type(number).__name__:
        raise TypeError("invalid number format")
    if 'str'==type(base).__name__:
        raise TypeError("invalid base format")
    if base<2:
        raise ValueError("Invalid base <2,  raised error")
    if base>36:
        raise ValueError("Invalid base >36,  raised error")

    string=[]
    while number>=base:
        string.append(number%base)
        number=number/base
    string.append(number)
    string=list(reversed(string))#reversing the remainders list
    if base>=10:
        alphabets=['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
        dictionary=dict(zip(range(10,36),alphabets))
        for x in range(len(string)):
            if string[x] in dictionary:
                string[x]=dictionary[string[x]]

    return ''.join(str(x) for x in string)#converting list  into an string



def test_to_base():
    assert "100" == convert(4,2)
    assert "FF" == convert(255,16)
    assert "377" == convert(255, 8)
    assert "JJ" == convert(399, 20)

    try:
        convert(10,1)
        assert False, "Invalid base <2 did not raise error"
    except ValueError as ve:
        print ve

    try:
        convert(10, 40)
        assert False, "Invalid base >40 did not raise error"
    except ValueError as ve:
        print ve

    try:
        convert("100", 10)
        assert False, "Invalid number did not raise error"
    except TypeError as te:
        print te

    try:
        convert(100, "10")
        assert False, "Invalid base did not raise error"
    except TypeError as te:
        print te