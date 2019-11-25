fn accum(s:&str)->String {
    let mut vec: Vec<char> = Vec::new();
    let mut iter = 0; 
    for c in s.chars(){
        vec.push(c.to_ascii_uppercase());
        for _ in 0..iter{
            vec.push(c.to_ascii_lowercase());
        }
        iter+=1;
        vec.push('-');
    }
    vec.pop();
    return vec.iter().collect();
}

fn main() {
}
