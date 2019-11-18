fn dig_pow(n: i64, p: i32) -> i64 {
    let mut _p = p as u32;
    let vec: Vec<i64> = n.to_string().chars().map(|x| {
        let res = (x.to_digit(10).unwrap() as i64).pow(_p as u32);
        _p += 1;
        return res;
    }).collect();
    let x: i64 = vec.iter().sum();
    
    if x % n == 0{
        return x / n;
    }
    return -1;
}

fn main() {
    println!("{}", dig_pow(695, 2));
}
