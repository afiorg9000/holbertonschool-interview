#!/usr/bin/python3
"""reads stdin line by line and computes metrics:"""
import sys

status_codes = {
    "200": 0,
    "301": 0,
    "400": 0,
    "401": 0,
    "403": 0,
    "404": 0,
    "405": 0,
    "500": 0
}


def logs():
    """Prints the accumulated logs"""
    print("File size: {}".format(size))
    for status in sorted(status_codes.keys()):
        if status_codes[status]:
            print("{}: {}".format(status, status_codes[status]))


if __name__ == "__main__":
    count = 0
    accumulated_logs = 0
    try:
        for line in sys.stdin:
            try:
                line = line.split()
                accumulated_logs += int(line[-1])
                if line[-2] in status_codes:
                    status_codes[line[-2]] += 1
            except Exception:
                pass
            if count == 9:
                logs()
                count = -1
            count += 1
    except KeyboardInterrupt:
        logs()
        raise
    logs()
