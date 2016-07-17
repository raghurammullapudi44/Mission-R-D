__author__ = 'Kalyan'

max_marks = 25

problem_notes = '''
Given a sentence transform all words in it according to
the following guidelines:

1. Move all vowels before all the consonents
2. Maintain relative ordering among the vowels and consonents.
3. If two equal letters come next to each other (case insensitive duplicates), drop the second letter
4. Preserve the case of the original letters.
5. Words are separated by spaces. Drop all non-letters like digits and punctuation and special chars in the sentence.

For e.g eagle becomes eaegl, ApPle become Aepl(repeating P dropped)

Write helper sub routines as required
'''
# do type checking, non-str should raise TypeException
def transform(sentence):
    pass
    input=sentence
    try:
        words_list=[]
        space_index=0
        space_index=input.index(' ')
        words_list.append(input[0:input.index(' ')])

        while space_index in range(len(input)):
            if input.index(' ',space_index+1):
                words_list.append(input[space_index+1:input.index(' ',space_index+1)])
                space_index=input.index(' ',space_index+1)
    except ValueError:
        if space_index == 0:
            words_list.append(input[space_index:len(input)+1])
        else:
            words_list.append(input[space_index+1:len(input)+1])
    x=[]
    for i in words_list:
        z=convert(rem_dup(rem_dig(i)))
        if z!=[]:
            x.append(z)
    y=''
    for i in x:
        y=y+''.join(i)+' '
    return y[:-1]


def convert(a):
    x=[]
    y=[]
    for i in a:
        if i.lower() in 'aeiou':
            x.append(i)
        else:
            y.append(i)
    x=x+y
    return x

def rem_dig(a):
    x=[]
    for i in a:
        if ((ord(i) >= 65 and ord(i)<=90)  or (ord(i) >= 97 and ord(i)<= 122)) and ord(i)!=32:
            x.append(i)
    return x

def rem_dup(nums):
    i = 1
    while i < len(nums):
        if nums[i].lower() == nums[i-1].lower():
            nums.pop(i)
            i -= 1
        i += 1
    return nums


def test_transform():
    #assert "AePl eaegl and ES" == transform("APple, eagle and SE00e")
    #assert "AePl eaegl and ES" == transform("APp,le, eagle and SE00e")
    assert 'e' == transform('    00,e    ')