import re
import html.parser
import requests
import time
from bs4 import BeautifulSoup


def HtmlWatch(url, seconds, iterations):
    old_lines = []
    try:
        htmlcontent = requests.get(url).text
    except requests.exceptions.Timeout:
        print("Timeout")
    except requests.exceptions.TooManyRedirects:
        print("Too many redirects")
    except requests.exceptions.RequestException as e:
        print(e)
    finally:
        soup = BeautifulSoup(htmlcontent, 'html.parser')
        for line in soup.prettify().split("\n"):
            old_lines.append(line)

        for _ in range(iterations):
            new_lines = []
            try:
                htmlcontent = requests.get(url).text
            except requests.exceptions.Timeout:
                print("Timeout")
            except requests.exceptions.TooManyRedirects:
                print("Too many redirects")
            except requests.exceptions.RequestException as e:
                print(e)
            finally:
                soup = BeautifulSoup(requests.get(url).text, 'html.parser')

                for line in soup.prettify().split("\n"):
                    new_lines.append(line)

                changes_counter = 0
                for iter, (old_line, new_line) in enumerate(zip(old_lines, new_lines)):
                    if old_line != new_line:
                        changes_counter += 1
                        print(f"Change number {changes_counter}: in line {iter}.\nOld line: {old_line}\nNew line:{new_line}")

                time.sleep(seconds)
            old_lines = new_lines

HtmlWatch("http://ap3.com/", 10, 50)
