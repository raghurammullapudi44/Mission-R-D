__author__ = 'Kalyan'

max_marks = 20

problem_notes = '''
Given 2 strings str1 and str2, find out the minimum number of right rotations str1 needs to undergo
to create str2. If is not possible, return -1

Notes:
1. Assume inputs are either None or valid strings
2. Write plain brute force code.
3. result should be -1 if not possible
4. If it is possible then give the 'minimum rotations' required.
5. No need for type checking.
'''

def get_right_rotations(str1, str2):
    pass
    if str1 and str2:
        if str1 != str2:
            count=0
            x=0
            while count != len(str1):
                str3=str1[len(str1)-count:]+str1[:(len(str1)-count)]
                if str3 != str2:
                    x=x+1
                else:
                    return x
                count=count+1
            else:
                return -1
        else:
            return 0
    else:
        return -1
# basic test given, write more tests to ensure correctness.
def test_get_right_rotations():
    assert 1 == get_right_rotations("abcd", "dabc")
    assert -1 == get_right_rotations(None, "dabc")
    assert 0 == get_right_rotations("abcd", "abcd")
    assert 4 == get_right_rotations("hello", "elloh")