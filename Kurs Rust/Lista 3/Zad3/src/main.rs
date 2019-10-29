use std::collections::HashMap;

struct Cipher {
    encodeMap : HashMap<char, char>,
    decodeMap : HashMap<char, char>
}

impl Cipher {
    fn new(map1: &str, map2: &str) -> Cipher {
        let mut encMap = HashMap::new();
        let mut decMap = HashMap::new();
        for v in map1.chars().zip(map2.chars()){
            encMap.insert(v.0, v.1);
            decMap.insert(v.1, v.0);
        }
        Cipher{encodeMap : encMap, decodeMap : decMap}
    }
  
    fn encode(&self, string: &str) -> String {
        let mut res = String::new();
        for c in string.chars(){
            res.push(*self.encodeMap.get(&c).unwrap_or(&c));
        }
        return res;
    }
  
    fn decode(&self, string: &str) -> String {
        let mut res = String::new();
        for c in string.chars(){
            res.push(*self.decodeMap.get(&c).unwrap_or(&c));
        }
        return res;
    }
}

fn main(){
}

#[test]
fn examples() {
  let map1 = "abcdefghijklmnopqrstuvwxyz";
  let map2 = "etaoinshrdlucmfwypvbgkjqxz";

  let cipher = Cipher::new(map1, map2);
  
  assert_eq!(cipher.encode("abc"), "eta");
  assert_eq!(cipher.encode("xyz"), "qxz");
  assert_eq!(cipher.decode("eirfg"), "aeiou");
  assert_eq!(cipher.decode("erlang"), "aikcfu");
}

#[test]
fn test2(){
    let map1 = "abcd";
    let map2 = "dcba";
    let cipher = Cipher::new(map1, map2);
    assert_eq!(cipher.encode("xyz"), "xyz");
    assert_eq!(cipher.encode("abc"), "dcb");
}

#[test]
fn test3(){
    let map1 = "";
    let map2 = "";
    let cipher = Cipher::new(map1, map2);
    assert_eq!(cipher.encode("abc"), "abc");
    assert_eq!(cipher.encode("xyz"), "xyz");
    assert_eq!(cipher.decode("eirfg"), "eirfg");
    assert_eq!(cipher.decode("erlang"), "erlang");
}