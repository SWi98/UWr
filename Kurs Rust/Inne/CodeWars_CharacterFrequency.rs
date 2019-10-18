use std::collections::BTreeMap;

fn letter_frequency(input: &str) -> BTreeMap<char, i32> {
    let mut res: BTreeMap<char, i32> = BTreeMap::new();
    let text= input.chars().filter(|x| (x >= &'a' && x <= &'z') || (x >= &'A' && x <= &'Z'))
            .map(|x| x.to_ascii_lowercase());
    for x in text{
        *res.entry(x).or_insert(0) += 1;
    }
    res
}

fn main(){
    println!("{:?}", letter_frequency("aaAabb dddDD hhcc"));
}