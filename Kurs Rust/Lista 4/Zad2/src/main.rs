fn even_numbers(array: &Vec<i32>, number: usize) -> Vec<i32> {
    let x : Vec<i32> = array.iter().filter(|x| *x % 2 == 0).cloned().collect();
    x[x.len() - number..].to_vec()
}

fn main() {
}

#[test]
fn test1() {
    assert_eq!(even_numbers(&vec!(1, 2, 3, 4, 5, 6, 7, 8, 9), 3), vec!(4, 6, 8));
}
#[test]
fn test2() {
    assert_eq!(even_numbers(&vec!(-22, 5, 3, 11, 26, -6, -7, -8, -9, -8, 26), 2), vec!(-8, 26));
}
#[test]
fn test3() {
    assert_eq!(even_numbers(&vec!(1, 2, 3, 4), 1), vec!(4));
}
#[test]
fn test4() {
    assert_eq!(even_numbers(&vec!(), 0), vec!());
}
#[test]
fn test5() {
    assert_eq!(even_numbers(&vec!(1, 2, 3, 4), 0), vec!());
}
#[test]
fn test6() {
    assert_eq!(even_numbers(&vec!(-2, -4, -6, -8), 4), vec!(-2, -4, -6, -8));
}
#[test]
fn test7() {
    assert_eq!(even_numbers(&vec!(1, 2, 3, 4), 1), vec!(4));
}
#[test]
fn test8() {
    assert_eq!(even_numbers(&vec!(100, 25, 10, 5), 2), vec!(100, 10));
}
#[test]
fn test9() {
    assert_eq!(even_numbers(&vec!(1, 3, 5, 7, 9), 0), vec!());
}
#[test]
fn test10() {
    assert_eq!(even_numbers(&vec!(111, 199, 200, 211), 1), vec!(200));
}

