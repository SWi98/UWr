fn find_digit(num: i32, nth: i32) -> i32 {
    if nth <= 0 {
        return -1;
    }
    if num < 0{
        let num = num * (-1);
    }
    num.to_string().chars().rev().collect::<String>().as_bytes()[(nth - 1) as usize] as i32 - 48
}

fn main() {
}

#[test]
fn test1(){
    assert_eq!(find_digit(-123, 3), 1);
}