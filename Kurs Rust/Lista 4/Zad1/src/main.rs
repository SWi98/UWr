fn find_digit(num: i32, nth: i32) -> i32 {
    let mut number = num;

    if nth <= 0 {
        return -1;
    }

    if num < 0{
        number = num * (-1);
    }

    let str = number.to_string().chars().rev().collect::<String>();

    if (str.len() as i32) < nth{
        return 0;
    }

    str.as_bytes()[(nth - 1) as usize] as i32 - 48
}

fn main() {
    println!("{}", find_digit(129, 2));
}

#[test]
fn test1() {
    assert_eq!(find_digit(5673, 4), 5);
}
#[test]
fn test2(){
    assert_eq!(find_digit(129, 2), 2);
}
#[test]
fn test3(){
    assert_eq!(find_digit(-2825, 3), 8);
}
#[test]
fn test4(){
  assert_eq!(find_digit(-456, 4), 0);
}
#[test]
fn test5(){
  assert_eq!(find_digit(0, 20), 0);
}
#[test]
fn test6(){
  assert_eq!(find_digit(65, 0), -1);
}
#[test]
fn test7(){
  assert_eq!(find_digit(24, -8), -1);
}
#[test]
fn test8(){
  assert_eq!(find_digit(0, 2), 0);
}
#[test]
fn test9(){
  assert_eq!(find_digit(-0, -8), -1);
}
#[test]
fn test10(){
  assert_eq!(find_digit(123456789, 9), 1);
}
