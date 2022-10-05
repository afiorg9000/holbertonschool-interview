#!/usr/bin/python3
"""determines if a given data set represents a valid UTF-8 encoding."""


def Binary(number):
    """ Function to convert a base 10 to binary"""
    binary = bin(number).replace('0b', '')
    return '0' * (8 - len(binary)) + binary


def validUTF8(data):
    """determines if a given data set represents a valid UTF-8 encoding."""
    i = 0
    while i < len(data):
        if Binary(data[i])[0] == '0':
            i += 1
        elif (Binary(data[i])[:3] == '110' and i + 1 < len(data) and
                Binary(data[i + 1])[:2] == '10'):
            i += 2
        elif (Binary(data[i])[:4] == '1110' and i + 2 < len(data) and
                Binary(data[i + 1])[:2] == '10' and
                Binary(data[i + 1])[:2] == '10'):
            i += 3
        elif (Binary(data[i])[:5] == '11110' and i + 3 < len(data) and
                Binary(data[i + 1])[:2] == '10' and
                Binary(data[i + 2])[:2] == '10' and
                Binary(data[i + 3])[:2] == '10'):
            i += 4
        else:
            return False
    return True
