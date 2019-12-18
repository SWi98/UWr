fn game(n: u64) -> Vec<u64> {
    if n%2==0{
        return vec![n * n / 2];
    }
    else{
        return vec![n * n, 2];
    }
}
fn main() {
    println!("Hello, world!");
}
#[test]
fn test1(){
    assert_eq!(game(204), vec![20808]);
}
#[test]
fn test2(){
    assert_eq!(game(750001), vec![562501500001, 2]);
}
#[test]
fn test3(){
    assert_eq!(game(5014), vec![12570098]);
}
#[test]
fn test4(){
    assert_eq!(game(807), vec![651249, 2]);
}
#[test]
fn test5(){
    assert_eq!(game(1), vec![1, 2]);
}
#[test]
fn test6(){
    assert_eq!(game(0), vec![0]);
}
#[test]
fn test7(){
    assert_eq!(game(2), vec![2]);
}