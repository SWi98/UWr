fn count_bits(n: i64) -> u32 {
    n.count_ones()
}

fn main() {
}

#[test]
fn test1(){
    assert_eq!(count_bits(0), 0);
}
#[test]
fn test2(){
    assert_eq!(count_bits(4), 1);
}
#[test]
fn test3(){
    assert_eq!(count_bits(7), 3);
}
#[test]
fn test4(){
    assert_eq!(count_bits(9), 2);
}
#[test]
fn test5(){
    assert_eq!(count_bits(10), 2);
}
#[test]
fn test6(){
    assert_eq!(count_bits(28), 3);
}
#[test]
fn test7(){
   assert_eq!(count_bits(20), 2); 
}
#[test]
fn test8(){
    assert_eq!(count_bits(16), 1);
}
#[test]
fn test9(){
    assert_eq!(count_bits(15), 4);
}
#[test]
fn test10(){
    assert_eq!(count_bits(11), 3);
}