#!/usr/bin/python3
"""reads stdin line by line and computes metrics:"""
import sys

if __name__ == '__main__':
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
    count = 1
    size = 0

    def parse_line(line):
        """parse line"""
        try:
            parsed_line = line.split()
            status_code = parsed_line[-2]
            if status_code in status_codes.keys():
                status_codes[status_code] += 1
            return int(parsed_line[-1])
        except Exception:
            return 0

    def logs():
        """prints the accumulated logs"""
        print("File size: {}".format(size))
        for key in sorted(status_codes.keys()):
            if status_codes[key]:
                print("{}: {}".format(key, status_codes[key]))

    try:
        for line in sys.stdin:
            size += parse_line(line)
            if count % 10 == 0:
                logs()
            count += 1
    except KeyboardInterrupt:
        logs()
        raise
    logs()
