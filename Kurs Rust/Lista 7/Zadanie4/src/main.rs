fn john_and_ann(n: i32) -> (Vec<i32>, Vec<i32>){
    let mut john_vec: Vec<i32> = vec![0];
    let mut ann_vec: Vec<i32> = vec![1];
    for i in 1..n{
        john_vec.push(i - ann_vec[john_vec[(i-1) as usize] as usize]);
        ann_vec.push(i - john_vec[ann_vec[(i-1) as usize] as usize]);
    }
    return (john_vec, ann_vec);
}

fn john(n: i32) -> Vec<i32> {
    john_and_ann(n).0
}
fn ann(n: i32) -> Vec<i32> {
    john_and_ann(n).1
}
fn sum_john(n: i32) -> i32 {
    john(n).iter().sum()
}
fn sum_ann(n: i32) -> i32 {
    ann(n).iter().sum()
}

fn main() {
}

fn test_john(n: i32, exp: Vec<i32>) -> () {
    assert_eq!(john(n), exp)
}
fn test_ann(n: i32, exp: Vec<i32>) -> () {
    assert_eq!(ann(n), exp)
}
fn test_sum_john(n: i32, exp: i32) -> () {
    assert_eq!(sum_john(n), exp)
}
fn test_sum_ann(n: i32, exp: i32) -> () {
    assert_eq!(sum_ann(n), exp)
}

#[test]
fn test_test_john1() {
    test_john(11, vec![0, 0, 1, 2, 2, 3, 4, 4, 5, 6, 6]);
}
#[test]
fn test_test_john2() {
    test_john(14, vec![0, 0, 1, 2, 2, 3, 4, 4, 5, 6, 6, 7, 7, 8]);
}
#[test]
fn test_test_ann1() {
    test_ann(6, vec![1, 1, 2, 2, 3, 3]);
}
#[test]
fn test_test_ann2() {
    test_ann(15, vec![1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6, 7, 8, 8, 9]);
}
#[test]
fn test_test_sum_john1() {
    test_sum_john(75, 1720);
}
#[test]
fn test_test_sum_john2() {
    test_sum_john(78, 1861);
}
#[test]
fn test_test_sum_ann1() {
    test_sum_ann(115, 4070);
}
#[test]
fn test_test_sum_ann2() {
    test_sum_ann(150, 6930);
}