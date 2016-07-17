__author__ = 'Kalyan'

notes = '''
 This problem will require you to put together many things you have learnt
 in earlier units to solve a problem.

 In particular you will use functions, nested functions, file i/o, functions, lists, dicts, iterators, generators,
 comprehensions,  sorting etc.

 Read the constraints carefully and account for all of them. This is slightly
 bigger than problems you have seen so far, so decompose it to smaller problems
 and solve and test them independently and finally put them together.

 Write subroutines which solve specific subproblems and test them independently instead of writing one big
 mammoth function.

 Do not modify the input file, the same constraints for processing input hold as for unit4_assignment_01
'''

problem = '''
 Given an input file of words (mixed case). Group those words into anagram groups and write them
 into the destination file so that words in larger anagram groups come before words in smaller anagram sets.

 With in an anagram group, order them in case insensitive ascending sorting order.

 If 2 anagram groups have same count, then set with smaller starting word comes first.

 For e.g. if source contains (ant, Tan, cat, TAC, Act, bat, Tab), the anagram groups are (ant, Tan), (bat, Tab)
 and (Act, cat, TAC) and destination should contain Act, cat, TAC, ant, Tan, bat, Tab (one word in each line).
 the (ant, Tan) set comes before (bat, Tab) as ant < bat.

 At first sight, this looks like a big problem, but you can decompose into smaller problems and crack each one.

 source - file containing words, one word per line, some words may be capitalized, some may not be.
 - read words from the source file.
 - group them into anagrams. how?
 - sort each group in a case insensitive manner
 - sort these groups by length (desc) and in case of tie, the first word of each group
 - write out these groups into destination
'''

import unit4utils
import string


def anagram_sort(source,destination):
    source = unit4utils.open_input_file("unit4_testinput_02.txt")

    all_words=[]
    for x in source.readlines():
        if x[0]!='#' and x[0]!=' ' and x[0]!='\n':
                all_words.append(x.strip())
    source.close()

    sorted_anagram_groups=grouping_anagrams(all_words)
    write_to_result(sorted_anagram_groups,destination)


def grouping_anagrams(all_words):
    parent_anagrams=list(set(''.join(sorted(x.lower())) for x in all_words))
    values=[range(0) for x in range(len(parent_anagrams))]

    anagram_dictionary=dict(zip(parent_anagrams,values))

    for x in all_words:
        parent_anagram_word=''.join(sorted(x.lower()))
        if parent_anagram_word in anagram_dictionary.keys():
            anagram_dictionary[parent_anagram_word].append(x)

    return sort_caseinsencitive(anagram_dictionary.values())


def sort_caseinsencitive(anagram_groups):
    for x in anagram_groups:
        x.sort(key=lambda x:x.lower())
    return arrange_dec_ties_asc(anagram_groups)

def sort_key(item):
    # descending by group length, ascending by first word in case of tie
    return -len(item),item[0].lower()

def arrange_dec_ties_asc(anagram_groups):
    anagram_groups.sort(key=sort_key)
    return anagram_groups

def write_to_result(anagram_groups,destination):
    destination=unit4utils.open_temp_file("unit4_output_02.txt","wb")
    for x in anagram_groups:
        for y in range(len(x)):
            destination.writelines(x[y]+'\n')
    destination.close()


def test_anagram_sort():
    source = unit4utils.get_input_file("unit4_testinput_02.txt")
    expected = unit4utils.get_input_file("unit4_expectedoutput_02.txt")
    destination = unit4utils.get_temp_file("unit4_output_02.txt")
    anagram_sort(source, destination)
    #print open(destination).readlines()
    result = [word.strip() for word in open(destination)]
    expected = [word.strip() for word in open(expected)]
    assert expected == result
