import re
import html.parser
import requests
import time
from multiprocessing import Process, Lock
from concurrent.futures import ThreadPoolExecutor
from bs4 import BeautifulSoup

lock = Lock()

def HtmlWatch(url, seconds, iterations):
    old_lines = []
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
            soup = BeautifulSoup(htmlcontent, 'html.parser')
            for line in soup.prettify().split("\n"):
                new_lines.append(line)
            #print(f"{url} - iteration nr {_}")
            changes_counter = 0
            for iter, (old_line, new_line) in enumerate(zip(old_lines, new_lines)):
                if old_line != new_line:
                    changes_counter += 1
                    lock.acquire()
                    print(f"Change at {url} number {changes_counter}: in line {iter}.\nOld line: {old_line}\nNew line:{new_line}")
                    lock.release()

            time.sleep(seconds)
        old_lines = new_lines


def run(lists):
    if __name__ == '__main__':                      # https://stackoverflow.com/questions/20222534/python-multiprocessing-on-windows-if-name-main
        processes = []
        for arg in lists:
            p = Process(target = HtmlWatch, args = arg)
            p.start()
            processes.append(p)
        for p in processes:
            p.join()


examples = [["http://ap3.com/", 10, 10], ["https://www.ii.uni.wroc.pl/~marcinm/", 7, 5]]
run(examples)
#HtmlWatch("http://ap3.com/", 10, 3)
#HtmlWatch("https://www.ii.uni.wroc.pl/~marcinm/", 7, 10)
