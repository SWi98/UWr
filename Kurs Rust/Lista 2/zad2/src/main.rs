/*use std::collections::HashSet;

fn longest(a1: &str, a2: &str) -> String {
    let mut letters = HashSet::new();
    let a1a2 = a1.to_string() + &a2.to_string();
    let mut res = Vec::new();
    for c in a1a2.chars(){
        if !letters.contains(&c){
            res.push(c);
            letters.insert(c);
        }
    }
    res.sort();
    return res.iter().collect();
}*/

fn longest(a1: &str, a2: &str) -> String {
    let mut res: Vec<char> = a1.chars().collect();
    res.extend(a2.chars());
    res.sort();
    res.dedup();
    res.iter().collect()
}


fn main() {
}

fn testing(s1: &str, s2: &str, exp: &str) -> () {
    println!("s1:{:?} s2:{:?}", s1, s2);
    println!("{:?} {:?}", longest(s1, s2), exp);
    println!("{}", longest(s1, s2) == exp);
    assert_eq!(&longest(s1, s2), exp)
}

#[test]
fn test1() {
    testing("aretheyhere", "yestheyarehere", "aehrsty");
}
#[test]
fn test2(){
    testing("loopingisfunbutdangerous", "lessdangerousthancoding", "abcdefghilnoprstu");
}
#[test]
fn test3(){
    testing("", "", "");
}
#[test]
fn test4(){
    testing("abcd", "abcdx", "abcdx");
}
#[test]
fn test5(){
    testing("zxyyxz", "baaa", "abxyz");
}
