require 'pp'


def palindrome?(str)
  res = str.downcase
  res = res.gsub(/[^a-z]/, '')
  res == res.reverse
end


def count_words(str)
  h = Hash.new
  res = str.downcase
  res = res.gsub(/[^a-z, \\S]/, '')
  words = res.split
  words.each do
    |word|
    if h.has_key?(word)
      h[word] += 1
    else
      h[word] = 1
    end
  end
  h
end


def same23?(arr)
  if arr.count != 5
    return false
  end
  a = arr.count('a')
  b = arr.count('b')
  c = arr.count('c')
  if (a == 3 and (b == 2 or c == 2)) or (b == 3 and (a == 2 or c == 2)) or (c == 3 and (a == 2 or b == 2))
    return true
  else
    return false
  end
end


puts("Zad1: ")
puts palindrome?("A man, a plan, a canal -- Panama") #=> true
puts palindrome?("Madam, I'm Adam!") # => true
puts palindrome?("Abracadabra") # => false
puts palindrome?("") # => true

puts("\nZad2: ")
pp count_words("A man, a plan, a canal -- Panama")
pp count_words("! %% abra *kada kada bra")

puts("\nZad3: ")
puts same23?(["a", "a", "a", "b", "b"])
puts same23?(["a", "b", "c", "b", "c"])
puts same23?(["a", "a", "a", "a", "a"])
