fn get_count(string: &str) -> usize {
  let mut vowels_count: usize = 0;
  for c in string.chars(){
      match c{
          'a' | 'e' | 'i' | 'o' | 'u' => vowels_count += 1,
          _ => (),
      }
  } 
  vowels_count
}

fn main(){
}

#[test]
fn test1() {
  assert_eq!(get_count("abracadabra"), 5);
}

#[test]
fn test2(){
    assert_eq!(get_count("aeiou"), 5);
}

#[test]
fn test3(){
    assert_eq!(get_count(""), 0);
}

#[test]
fn test4(){
    assert_eq!(get_count("xxxxxaxxxxxexxxxxxixxxxxxoxxxxxxxxxxxx"), 4);
}

#[test]
fn test5(){
    assert_eq!(get_count("xyyxyxyxyxyxyxyxplplplplplqqqqqqqqqqqqqqq"), 0);
}