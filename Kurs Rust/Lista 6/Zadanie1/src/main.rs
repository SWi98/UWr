fn encode(msg: String, n: i32) -> Vec<i32>{
    let mut res: Vec<i32> = msg.chars().map(|ch| ch as i32  - 'a' as i32 + 1).collect();
    let digits: Vec<i32> = n.to_string().chars().map(|ch| ch.to_digit(10).unwrap() as i32).collect();

    for i in 0..res.len(){
        res[i] += digits[(i as usize % digits.len())];
    }

    res
}

fn main() {
    println!("{}", 'a' as i32);
}
#[test]
fn test(){
    assert_eq!(vec![20, 12, 18, 30, 21], encode("scout".to_string(), 1939));
}
