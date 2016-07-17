__author__ = 'Kalyan'

max_marks = 35 # 15 marks for encode and 20 for decode

problem_notes ='''
 This problem deals with number conversion into a custom base 5 notation and back.
 In this notation, the letters a to e are used for digits 0 to 4.

 E.g. decimal 10 in this custom base 5 notation is "ca", decimal 5 is "ba" etc.

 Your job is to write encoding and decoding (both) routines to deal with this notation.
'''

# Notes:
# - If number is not a valid int or long raise TypeError
# - Negative numbers should result in a - prefix to the result similar to how bin works
#  use lower case letters in your result [a to e].
def to_custom_base5(number):
    pass
    if 'int' != type(number).__name__ and 'long' != type(number).__name__ :
        raise TypeError
    flag=1
    if number<0:
        flag=0
    number=abs(number)
    x='abcde'
    d=dict(zip(range(5),x))
    number=to_base_5(number)
    nlist=[int(i) for i in number]
    if flag==0:
        y='-'
    else:
        y=''
    for i in nlist:
        y=y+d[i]
    return y

def to_base_5(n):
    s=[]
    while n:
        s.append(str(n%5))
        n=n/5
    return ''.join(s[::-1])


# Notes:
# - if s is not a string, raise TypeError
# - if the encoding is not right or empty string, raise ValueError
# - allow both - and + as prefixes which represent sign.
# - allow trailing and starting spaces (but not once the sign or number starts)
# - allow both capital and small letters.
# - return a int or long that corresponds to the number.
def from_custom_base5(s):
    pass
    if 'str' != type(s).__name__ or s=='':
        raise TypeError
    x='abcde'
    d=dict(zip(x,range(5)))
    y=[]
    flag=1
    if s[0]== '-' or s[0] == '+':
        s=s[1:]
        flag=0
    for i in s.lower():
        y.append(d[i])
    number=0
    for i in y:
        number=number+i*10
    number=int(str(number),5)
    if flag==0:
        number=-number
    return number



# a basic test is given, write your own tests based on constraints.
def test_to_custom_base5():
    assert "ca" == to_custom_base5(10)
    assert "-ca" == to_custom_base5(-10)

# a basic test is given, write your own tests based on constraints.
def test_from_custom_base5():
    assert 10 == from_custom_base5("ca")
    assert 17 == from_custom_base5("dc")
    assert -10 == from_custom_base5("-CA")