__author__ = 'Kalyan'

notes = '''
1. Read instructions for the function carefully and constraints carefully.
2. Try to generate all possible combinations of tests which exhaustively test the given constraints.
3. If behavior in certain cases is unclear, you can ask on the forums
'''
from placeholders import *

# Convert a sentence which has either or to only the first choice.
# e.g we could either go to a movie or a hotel -> we could go to a movie.
# note: do not use intermediate lists (string.split), only use string functions
# assume words are separated by spaces. you can use control flow statements
# So sentence is of form <blah> either <something> or <somethingelse> and gets converted to <blah> <something>
# if it is not of the correct form, you just return the original sentence.
def prune_either_or(sentence):
    pass
    if sentence:
        if ' either ' in sentence and 'either or' not in sentence:
            startIndex_EITHER=sentence.index('either ')    #finding the startingindex of 'either '
            if ' or' in sentence[(startIndex_EITHER+8):] and startIndex_EITHER!=0:
                sentence=sentence.replace('either ','')             #removing 'either ' from sentence
                startIndex_OR=sentence.index(' or',startIndex_EITHER)   #finding the startingindex of ' or'
                return sentence[:startIndex_OR]         #returning the sentence by removing part followed by ' or' which is only a few indexes away from 'either ' or after the 'either '
            else:
                return sentence         #return original sentence which is not in correct form
        else:
            return sentence     #return original sentence which is not in correct form

def test_prune_either_or_student():
    pass
    assert None == prune_either_or(None)
    assert 'my dream is to crack KONYLABS' == prune_either_or('my dream is to crack either KONYLABS or TERRADATA')
    assert 'we could go to a movie' == prune_either_or('we could either go to a movie or a hotel')
    assert 'we will watch I' == prune_either_or('we will watch either I or gopalagopala')
    assert 'on monday or tuesday ram will play cricket' == prune_either_or('on monday or tuesday ram will play either cricket or vollyball in Tournment')
    assert '<blaw1> or <blaw2> <something>' == prune_either_or('<blaw1> or <blaw2> either <something> or <somethingelse>')
    #incorrect sentences
    assert 'either KONYLABS or TERRADATA' == prune_either_or('either KONYLABS or TERRADATA')
    assert 'Ram or shyam will do that work' == prune_either_or('Ram or shyam will do that work')
    assert 'we have no problem with either of the tasks' == prune_either_or('we have no problem with either of the tasks')
    assert 'i had passion towards coding' == prune_either_or('i had passion towards coding')
    assert '<blaw1> or <blaw2> either <something>' == prune_either_or('<blaw1> or <blaw2> either <something>')
    assert "Two mythical cities eitheron and oregon" == prune_either_or("Two mythical cities eitheron and oregon")
    assert "It is neither here nor there" == prune_either_or("It is neither here nor there")
    assert "It is neither here or there" == prune_either_or("It is neither here or there")

# these tests run only on our runs and will be skipped on your computers.
# DO NOT EDIT.
import pytest
def test_prune_either_or_server():
    servertests = pytest.importorskip("unit6_server_tests")
    servertests.test_prune_either_or(prune_either_or)
