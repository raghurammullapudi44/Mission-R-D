__author__ = 'Kalyan'

notes = '''
1. Read instructions for each function carefully.
2. Feel free to create new functions if needed. Give good names though :)
3. Use builtins and datatypes that we have seen so far.
4. If something about the function spec is not clear, use the corresponding test
   for clarification

Read: https://docs.python.org/2/howto/sorting.html. We have not covered lambdas etc.
so don't use them. You can define and use normal functions which do the same thing
if required.
'''

# Sort the words list that are passed in by word length instead of word content.
# e.g ["apple", "dog", "elephant"] should result in ["elephant", "apple", "dog"]
# hint: use list.sort, don't write your own.
# sort the list inplace
def sort_by_length(words):
    if words==None:
        return None
    else:
        lengths=[]
        for x in range(len(words)):
            lengths.append(len(words[x]))
        lengths.sort(reverse=True)
        result=[]
        for y in range(len(lengths)):
            for z in range(len(words)):
                if lengths[y]==len(words[z]):
                    if words[z] not in result:
                        result.append(words[z])
                        break
        return result


# sort the words list in place by number of vowels in the word in descending order
# same hint as above.
def sort_by_vowel_count(words):
    #pass
    if words==None:
        return None
    else:
        vowels=[]
        for x in range(len(words)):
            vowels.append(len(list(set(['a','e','i','o','u'])&set(words[x]))))
        vowels.sort(reverse=True)
        result=[]
        for x in range(len(vowels)):
            for y in range(len(words)):
                if vowels[x]==len(list(set(['a','e','i','o','u'])&set(words[y]))):
                    if words[y] not in result:
                        result.append(words[y])
                        break
        return result


def single_sort_by_len_test(input, result):
    #sort_by_length(input)
    assert result == sort_by_length(input) # inplace sort required.

def test_sort_by_length():
    single_sort_by_len_test(["dog", "apple", "bear"], ["apple", "bear", "dog"])
    single_sort_by_len_test(["apple", "dog",  "bear"], ["apple", "bear", "dog"])
    single_sort_by_len_test(["dog", "apple",  "cat"],  ["apple", "dog", "cat"])
    single_sort_by_len_test(["one", "two", "three", "four"],  ["three", "four", "one", "two"])
    single_sort_by_len_test([], [])
    single_sort_by_len_test(None, None)


def single_sort_by_vc_test(input, result):
    #sort_by_vowel_count(input)
    assert result == sort_by_vowel_count(input)

def test_sort_by_vowel_count():
    single_sort_by_vc_test(["engine", "ant", "aeiou"], ["aeiou", "engine", "ant"])
    single_sort_by_vc_test(["engine", "ant", "aeroplane", "key", "bcdgcdbcd"], ["aeroplane", "engine", "ant", "key", "bcdgcdbcd"])
    single_sort_by_vc_test([], [])
    single_sort_by_vc_test(None, None)
