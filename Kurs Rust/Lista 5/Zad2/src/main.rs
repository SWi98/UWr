fn descending_order(x: u64) -> u64 {
    let mut vec: Vec<u64> = x.to_string().chars().map(|z| z.to_digit(10).unwrap() as u64).collect();
    vec.sort();
    vec.reverse();
    vec.iter().fold(0, |acc, z| acc * 10 + *z)
}

fn main() {
}

#[test]
fn returns_expected() {
    assert_eq!(descending_order(0), 0);
}
#[test]
fn test2(){
    assert_eq!(descending_order(1), 1);
}
#[test]
fn test3(){
    assert_eq!(descending_order(15), 51);
}
#[test]
fn test4(){
    assert_eq!(descending_order(1021), 2110);
}
#[test]
fn test5(){
    assert_eq!(descending_order(123456789), 987654321);
}
#[test]
fn test6(){
    assert_eq!(descending_order(145263), 654321);
}
#[test]
fn test7(){
    assert_eq!(descending_order(1254859723), 9875543221);
}
#[test]
fn test8(){
    assert_eq!(descending_order(1234), 4321);
}
#[test]
fn test9(){
    assert_eq!(descending_order(100000000), 100000000);
}
#[test]
fn test10(){
    assert_eq!(descending_order(9988776655), 9988776655);
}