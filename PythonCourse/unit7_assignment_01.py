__author__ = 'Kalyan'

profiling_timing = '''
This involves adding sufficient time.clock calls at appropriate places and then calculating difference to calculate
elapsed time.

http://docs.python.org/2/library/time.html?highlight=time.clock#time.clock

This is similar to print debugging, but once you have narrowed down code to a small code section by other means,
this can be very useful and precise.

Generally you will study performance as you vary the input across a range e.g. count = 10, 100, 1000, 10000

profile the 4 methods in unit7_conversion_methods.py using time.clock() in this assignment.

for each value of count, execute the method 5 times and print out the min value and the actual 5 values.
output should look like (a total of 16 lines):
numbers_string1, count = 10, min = 0.0001, actuals = [0.0001, 0.0002, 0.0001, ...]
numbers_string1, count = 100, min = 0.002, actuals = [0.002, 0.002, 0.003, ...]
....
numbers_string4, count = 10000, min = 0.1 actuals = [....]

 Note: This is a python script which can be run from command line (python.exe <script>.py) or from pycharm (Right click -> Run <script>
 and not the usual pytest tests we have been using so far.
'''

from unit7_conversion_methods import *
import time

# write clean code to run all the profiles in one go using loops, lists etc. Note that functions are first class objects
# in python so you can hold them in a list.
def profile_clock():
    pass

    methods=[numbers_string1,numbers_string2,numbers_string3,num_strings4]

    for i in range(4):
        for j in range(1,5):
            actual=[]
            for k in range(4):
                time1 = time.clock()
                methods[i](pow(10,j))
                actual.append(time.clock()-time1)
            print methods[i].__name__,", ",'count=',pow(10,j),", ","min=",min(actual),", ",actual



# write your findings on what is the most optimal method and what you learnt in the process.
summary = '''
1.I found that method 2 ie numbers_string2() is the most optimal method
2.Till now i didnot have any idea of time taking to complete a process except interms of complexities in algorithms
3.Though the algorithms seems to be have same run time visually,differnet algorithms may take different cpu cycles to complete the process
4.Very Very interesting and fasinating topic in choosing good codes in optimization of algorithms
'''

if __name__ == "__main__":
    profile_clock()
