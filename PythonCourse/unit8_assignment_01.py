__author__ = 'Kalyan'

problem = """
 We are going to revisit unit4 assignment2 for this problem.

 Given an input file of words (mixed case). Group those words into anagram groups and write them
 into the destination file so that words in larger anagram groups come before words in smaller anagram sets.

 With in an anagram group, order them in case insensitive ascending sorting order.

 If 2 anagram groups have same count, then set with smaller starting word comes first.

 For e.g. if source contains (ant, Tan, cat, TAC, Act, bat, Tab), the anagram groups are (ant, Tan), (bat, Tab)
 and (Act, cat, TAC) and destination should contain Act, cat, TAC, ant, Tan, bat, Tab (one word in each line).
 the (ant, Tan) set comes before (bat, Tab) as ant < bat.

 At first sight, this looks like a big problem, but you can decompose into smaller problems and crack each one.

 This program should be written as a command line script. It takes one argument the input file of words and outputs
 <input>-results.txt where <input>.txt is the input file of words.
"""
import sys
import unit4utils

def main():
    input = unit4utils.open_input_file("unit4_testinput_02.txt")
    load_words(input)

def load_words(input):
    all_words=[]
    for x in input.readlines():
        if x[0]!='#' and x[0]!=' ' and x[0]!='\n':
                all_words.append(x.strip())
    input.close()

    anagram_sort(all_words)


def anagram_sort(all_words):
    parent_anagrams=list(set(''.join(sorted(x.lower())) for x in all_words))
    values=[range(0) for x in range(len(parent_anagrams))]

    anagram_dictionary=dict(zip(parent_anagrams,values))

    for x in all_words:
        parent_anagram_word=''.join(sorted(x.lower()))
        if parent_anagram_word in anagram_dictionary.keys():
            anagram_dictionary[parent_anagram_word].append(x)

    sort_case_insencitive(anagram_dictionary.values())


def sort_case_insencitive(anagram_groups):
    for x in anagram_groups:
        x.sort(key=lambda x:x.lower())
    arrange_dec_ties_asc(anagram_groups)

def arrange_dec_ties_asc(anagram_groups):
    anagram_groups.sort(key=sort_key)
    write_to_result(anagram_groups)

def sort_key(item):
    # descending by group length, ascending by first word in case of tie
    return -len(item),item[0].lower()

def write_to_result(anagram_groups):
    result = unit4utils.get_temp_file("result.txt")
    result=unit4utils.open_temp_file("result.txt","wb")

    for x in anagram_groups:
        for y in range(len(x)):
            result.writelines(x[y]+'\n')

    result.close()

if __name__ == "__main__":
    main()
    #sys.exit(main())