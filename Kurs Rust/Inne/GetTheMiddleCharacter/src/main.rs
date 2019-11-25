fn get_middle(s:&str) -> &str {
    let n = s.len();
    let mut iter = 0;
    let mut res = String::new();
    for c in s.chars(){
        if s.len() % 2 == 0 && (s.len() / 2 == (iter + 1) || s.len() / 2 == (iter + 2)){
            res.push(c);
        }
    }
    let s2: String = res.to_owned();
    return &s2[..];
}

fn main() {
    println!("Hello, world!");
}
