use std::collections::BTreeMap;

fn letter_frequency(input: &str) -> BTreeMap<char, i32> {
    let mut btree = BTreeMap::new();
    for c in input.to_string().chars().filter(|x| *x != ' ' && x.is_alphanumeric()).collect::<String>().to_lowercase().chars(){
        *btree.entry(c).or_insert(0) += 1;
    }
    return btree;
}

fn main() {
    println!("{:?}", letter_frequency("!#$%&'()*+,./@[]^_"));
}
