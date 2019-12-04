use std::collections::BTreeMap;

fn order(sentence: &str) -> String {
    let mut res = String::new();
    let mut dict = BTreeMap::new();
    let words: Vec<&str> = sentence.split(" ").collect();
    for word in words{
        for c in word.chars(){
            if c.is_numeric(){
                dict.insert(c, word);
            }
        }
    }
    for (_, value) in dict.iter(){
        res += value;
        res.push(' ');
    }
    res.pop();
    return res;
}
    
fn main() {
    order("is2 Thi1s T4est 3a");
}

#[cfg(test)]
mod tests {
    use super::*;
    #[test]
    fn returns_expected() {
        assert_eq!(order("is2 Thi1s T4est 3a"), "Thi1s is2 3a T4est");
        assert_eq!(order(""), "");
    }
}