#!/usr/bin/python3
"""counts the number of times a word apppears in a subreddit"""
import requests


def count_words(subreddit, word_list):
    """Counts the number of times a word appears in a subreddit"""
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {'User-Agent': 'Mozilla/5.0 (Macintosh; Intel Mac OS X 10_10_1) \
    AppleWebKit/537.36 (KHTML, like Gecko) Chrome/39.0.2171.95 Safari/537.36'}
    params = {'limit': 100}
    r = requests.get(url, headers=headers, params=params,
                     allow_redirects=False)
    if r.status_code == 200:
        data = r.json().get('data')
        children = data.get('children')
        titles = [child.get('data').get(
            'title').lower().split() for child in children]
        words = [word for title in titles for word in title]
        word_count = {word: words.count(word) for word in word_list}
        word_count = {k: v for k, v in sorted(word_count.items(),
                                              key=lambda item: (-item[1],
                                                                item[0]))}
        for k, v in word_count.items():
            if v > 0:
                print("{}: {}".format(k, v))
    else:
        return None
