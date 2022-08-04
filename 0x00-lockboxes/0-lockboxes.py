#!/usr/bin/python3

def canUnlockAll(boxes):
    if len(boxes) == 0:
        return False

    keys = [0] # list that holds the keys  also initializes in box[0]
    for key in keys:
        for box in boxes[key]: #if the number of boxes the same as the number of keys
            if box not in keys and box < len(boxes): # if the unlocked box is not in the list of keys and the box is less than the length of boxes
                keys.append(box) # appends the box to the list of keys

    return len(keys) == len(boxes)