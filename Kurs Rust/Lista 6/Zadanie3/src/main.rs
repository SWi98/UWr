fn print(n: i32) -> Option<String> {
    if n < 0 || n % 2 == 0{
        return None; 
    }
    if n == 1{
        return Some("*\n".to_string());
    }
    let mut vec = Vec::new();
    for i in (1..= n).step_by(2){ 
        let mut res = String::new();
        for j in i/2..n/2{
            res.push(' ');
        }
        for j in 0..=i-1{
            res.push('*');
        }
        res += &"\n";
        vec.push(res.clone());
    }
    let mut res = String::new();
    /*res = "".to_string();
    for i in(0..=n){
        res.push('*');
    }
    res += &"\n";
    vec.push(res.clone());
    */
    for i in 0..(vec.len() -1){
        vec.push(vec[vec.len() - 2 - i*2].clone());
    }
    res = "".to_string();
    for v in vec{
        res += &(v);
    }
    return Some(res);
}

fn main() {
    println!("{:?}", print(5));
}