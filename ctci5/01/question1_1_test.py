import unittest
from question1_1 import *

class ExpectedResult(unittest.TestCase):
    def testEmptyStr(self):
        '''question1_1_unique must return True with empty strings'''
        result = question1_1_unique('')
        self.assertTrue(result)

    def testSingleCharStr(self):
        '''question1_1_unique must return True with single character strings'''
        result = question1_1_unique('a')
        self.assertTrue(result)

    def testDoubleCharStr(self):
        '''question1_1_unique must return True with double character strings that don't have the same characters'''
        result = question1_1_unique('ab')
        self.assertTrue(result)

    def testStrWithTwoConsChar(self):
        '''question1_1_unique must return False with strings that have two same consecutive characters'''
        result = question1_1_unique('aab')
        self.assertFalse(result)

    def testStrWithTwoNonConsChar(self):
        '''question1_1_unique must return False with strings that have two same non consecutive characters'''
        result = question1_1_unique('aba')
        self.assertFalse(result)

    def testStrWithNoConsChar(self):
        '''question1_1_unique must return True with strings that have all unique characters'''
        result = question1_1_unique('promise')
        self.assertTrue(result)


if __name__ == '__main__':
    unittest.main()

