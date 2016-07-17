__author__ = 'Kalyan'

problem = """
Pig latin is an amusing game. The goal is to conceal the meaning of a sentence by a simple encryption.

Rules for converting a word to pig latin are as follows:

1. If word starts with a consonant, move all continuous consonants at the beginning to the end
   and add  "ay" at the end. e.g  happy becomes appyhay, trash becomes ashtray, dog becomes ogday etc.

2. If word starts with a vowel, you just add an ay. e.g. egg become eggay, eight becomes eightay etc.

You job is to write a program that takes a sentence from command line and convert that to pig latin and
print it back to console in a loop (till you hit Ctrl+C).

e.g "There is, however, no need for fear." should get converted to  "Erethay isay, oweverhay, onay eednay orfay earfay."
Note that punctuation and capitalization has to be preserved

You must write helper sub routines to make your code easy to read and write.

Constraints: only punctuation allowed is , and . and they will come immediately after a word and will be followed
by a space if there is a next word. Acronyms are not allowed in sentences. Some words may be capitalized
(first letter is capital like "There" in the above example) and you have to preserve its capitalization in the
final word too (Erethay)
"""

import sys
def main():
    input=raw_input()
    while 0 in range(1):
        print pig_latin(input)

def pig_latin(input):
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

    return ' '.join(convert_pig_latin(words_list))

def convert_pig_latin(words_list):
    converted_words_list=[]

    for word in words_list:
        flag=0
        if word[0].isupper():
            flag=1
        if word[0].lower() in "aeiou":
            word=if_vowel(word)
        else:
            word=if_consonant(word)

        if flag==1:
            converted_words_list.append(word[0].upper()+word[1:])
        else:
            converted_words_list.append(word)

    return converted_words_list

def if_vowel(word):
    if word[-1] == ',' or word[-1] == '.':
        return word[0:-1]+'ay'+word[-1]
    else:
        return word+'ay'

def if_consonant(word):
    x=0
    if word[-1] == ',' or word[-1] == '.':
        while x in range(len(word)):
            if word[x].lower() not in 'aeiou':
                word=word[1:-1]+word[0].lower()+word[-1]
            else:
                word=word[:-1]+'ay'+word[-1]
                break
        return word
    else:
        while x in range(len(word)):
            if word[x].lower() not in 'aeiou':
                word=word[1:]+word[0].lower()
            else:
                word=word+'ay'
                break
        return word

if __name__ == "__main__":
    main()
    pass
    #sys.exit(main())