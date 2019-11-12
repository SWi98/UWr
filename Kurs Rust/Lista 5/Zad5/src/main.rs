fn dbl_linear(n: u32) -> u32{
    let mut u = vec![1];
    let mut y;
    let mut prev_y = 0;
    let mut z;
    let mut prev_z = 0;
    while u.len() < (n+1) as usize{
        y = u[prev_y] * 2 + 1;
        z = u[prev_z] * 3 + 1;
        if y <= z{
            prev_y += 1;
            u.push(y);
            if y == z{
                prev_z += 1;
            }
        }
        else{
            prev_z += 1;
            u.push(z);
        }
    }
    println!("{:?}", u);
    return u[n as usize];
}

fn main() {
    println!("{}", dbl_linear(25));
}

 #[test]
fn test1() {
    assert_eq!(dbl_linear(10), 22);
}
 #[test]
fn test2() {
    assert_eq!(dbl_linear(20), 57);
}
 #[test]
fn test3() {
    assert_eq!(dbl_linear(30), 91);
}
 #[test]
fn test4() {
    assert_eq!(dbl_linear(50), 175);
}
#[test]
fn test5(){
    assert_eq!(dbl_linear(100), 447);
}
#[test]
fn test6(){
    assert_eq!(dbl_linear(3), 7);
}
#[test]
fn test7(){
    assert_eq!(dbl_linear(1), 3);
}
#[test]
fn test8(){
    assert_eq!(dbl_linear(25), 79);
}
#[test]
fn test9(){
    assert_eq!(dbl_linear(101), 463);
}
#[test]
fn test10(){
    assert_eq!(dbl_linear(99), 418);
}


