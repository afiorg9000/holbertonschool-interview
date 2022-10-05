#!/usr/bin/python3
""" Module for UTF8_data class """


def to_bin(number):
    """ Function to convert a base 10 to binary
    Arg:
        number (int) - number
    Return:
         (str)
    """
    binary = bin(number).replace('0b', '')
    binary = '0' * (8 - len(binary)) + binary
    return binary


def validUTF8(data_set):
    """ A function to validate if a data set is a valid utf-8 format
    '00000000' == 0
    '10000000' == 128
    '11000000' == 192
    '11100000' == 224
    '11110000' == 240
    '11111000' == 248
    '11111100' == 252
    '11111110' == 254
    '11111111' == 255
    """
    # print(data_set, '\n', [to_bin(num) for num in data_set])
    val = data_set[0]
    if val > 255:
        # print('first if\n{} > {}'.format(to_bin(val), to_bin(255)))
        return False
    elif val & 128 == 0:
        # print('second if\n{} & {} = {}'.format(
        #     to_bin(val), to_bin(128), to_bin(val & 128)))
        num_of_byte = 1
    elif val & 224 == 192:
        # print('third if\n{} & {} = {}'.format(
        #     to_bin(val), to_bin(224), to_bin(val & 224)))
        num_of_byte = 2
    elif val & 240 == 224:
        # print('fourth if\n{} & {} = {}'.format(
        #     to_bin(val), to_bin(240), to_bin(val & 240)))
        num_of_byte = 3
    elif val & 248 == 240:
        # print('fifth if\n{} & {} = {}'.format(
        #     to_bin(val), to_bin(248), to_bin(val & 248)))
        num_of_byte = 4
    else:
        # print('last else')
        return False
    # print(len(data_set), num_of_byte)

    if len(data_set) < num_of_byte:
        return False

    for j in range(num_of_byte - 1):
        # print(to_bin(data_set[j]), to_bin(192), to_bin(128))
        if data_set[j] & 192 != 128 or data_set[j] > 255:
            return False
    return True