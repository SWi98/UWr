use std::collections::BTreeMap;

fn letter_frequency(input: &str) -> BTreeMap<char, i32> {
    let mut btree = BTreeMap::new();
    for c in input.to_string().chars().filter(|x| x.is_alphabetic()).collect::<String>().to_lowercase().chars(){
        *btree.entry(c).or_insert(0) += 1;
    }
    return btree;
}

fn main() {
    println!("{:?}", letter_frequency("!#$%&'()*+,./@[]^_"));
}

    #[test]
    fn test1() {
        let answer: BTreeMap<char, i32> =
        [('a', 2),
         ('c', 1),
         ('l', 1),
         ('t', 1),
         ('u', 1)]
         .iter().cloned().collect();
         
        assert_eq!(letter_frequency("actual"), answer);
    }
    #[test]
    fn test2() {
        let answer: BTreeMap<char, i32> =
        [('a', 3),
         ('b', 2),
         ('f', 1),
         ('p', 1),
         ('s', 1),
         ('t', 2),
         ('u', 1),
         ('x', 5)]
         .iter().cloned().collect();
         
        assert_eq!(letter_frequency("AaabBF UttsP xxxxx"), answer);
    }
    #[test]
    fn test3() {
        let answer: BTreeMap<char, i32> = BTreeMap::new();
         
        assert_eq!(letter_frequency(""), answer);
    }
    #[test]
    fn test4() {
        let answer: BTreeMap<char, i32> =
        [('a', 1),
         ('b', 1),
         ('c', 1),
         ('d', 1),
         ('e', 1),]
         .iter().cloned().collect();
         
        assert_eq!(letter_frequency("abcde"), answer);
    }
    #[test]
    fn test5() {
        let answer: BTreeMap<char, i32> =
        [('f', 1),
         ('g', 1),
         ('h', 1),
         ('i', 1),
         ('j', 1),]
         .iter().cloned().collect();
         
        assert_eq!(letter_frequency("fghij"), answer);
    }
    #[test]
    fn test6() {
        let answer: BTreeMap<char, i32> =
        [('a', 1),
         ('b', 1),
         ('c', 1),
         ('d', 1),
         ('e', 1),]
         .iter().cloned().collect();
         
        assert_eq!(letter_frequency("ABCDE"), answer);
    }
    #[test]
    fn test7() {
        let answer: BTreeMap<char, i32> =
        [('f', 1),
         ('g', 1),
         ('h', 1),
         ('i', 1),
         ('j', 1),]
         .iter().cloned().collect();
         
        assert_eq!(letter_frequency("FGHIJ"), answer);
    }
    #[test]
    fn test8() {
        let answer: BTreeMap<char, i32> = BTreeMap::new();
         
        assert_eq!(letter_frequency("12345"), answer);
    }
    #[test]
    fn test9() {
        let answer: BTreeMap<char, i32> =
        [('a', 1),
         ('b', 1),
         ('c', 1),
         ('d', 1),
         ('e', 1),]
         .iter().cloned().collect();        
       
         assert_eq!(letter_frequency("12345ABCDE"), answer);
    }
    #[test]
    fn test10() {
        let answer: BTreeMap<char, i32> =
        [('f', 1),
         ('g', 1),
         ('h', 1),
         ('i', 1),
         ('j', 1),]
         .iter().cloned().collect();
         
        assert_eq!(letter_frequency("../;!@#$FGHIJ"), answer);
    }
