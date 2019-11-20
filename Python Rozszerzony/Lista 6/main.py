import re
import html.parser
import requests
import time
from bs4 import BeautifulSoup


def HtmlWatch(url, seconds, iterations):
    old_lines = []
    soup = BeautifulSoup(requests.get(url).text, 'html.parser')
    for line in soup.prettify().split("\n"):
        old_lines.append(line)

    for i in range(iterations):
        new_lines = []
        soup = BeautifulSoup(requests.get(url).text, 'html.parser')

        for line in soup.prettify().split("\n"):
            new_lines.append(line)

        changes_counter = 0
        for iter, (old_line, new_line) in enumerate(zip(old_lines, new_lines)):
            if old_line != new_line:
                changes_counter += 1
                print(f"Change number {changes_counter}: in line {iter}.\nOld line: {old_line}\nNew line:{new_line}")

        time.sleep(seconds)

HtmlWatch("http://ii.uni.wroc.pl/", 10, 4)
#HtmlWatch("http://ap1.myserver.com/", 10, 4)
'''url = "http://ap1.myserver.com/"
soup = BeautifulSoup(requests.get(url).text, 'html.parser')
old_tags = []
for line in soup.prettify().split("\n"):
    old_tags.append(line)
time.sleep(5)
new_tags = []
soup = BeautifulSoup(requests.get(url).text, 'html.parser')
for line in soup.prettify().split("\n"):
    new_tags.append(line)

for (newline, oldline) in zip(new_tags, old_tags):
    if newline != oldline:'''
