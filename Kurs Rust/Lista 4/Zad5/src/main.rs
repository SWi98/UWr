use std::collections::HashSet;

fn sum_pairs(ints: &[i8], s: i8) -> Option<(i8, i8)> {
    let mut seen = HashSet::new();
    seen.insert(ints[0]);
    for i in 1..ints.len(){
        let needed = s - ints[i];
        if seen.contains(&needed){
            return Some((needed, ints[i]));
        }
        seen.insert(ints[i]);
    }
    return None;
}

fn sum_pairs_square(ints: &[i8], s: i8) -> Option<(i8, i8)> {
    let mut min_j: usize = ints.len();
    let mut res = None;
    for i in 0..min_j-1{
        for j in i+1..min_j{
            if ints[i] + ints[j] as i8 == s && j < min_j{
                res = Some((ints[i], ints[j]));
                min_j = j;
            }
        }
    }
    return res;
}

fn sum_pairs_square_v2(ints: &[i8], s: i8) -> Option<(i8, i8)> {
    for i in 1..ints.len(){
        let needed = s - ints[i];
        for j in 0..i{
            if ints[j] == needed{
                return Some((ints[j], ints[i]));
            }
        }
    }
    return None;
}


fn main() {
    let l5 = [10, 5, 2, 3, 7, 5];
    println!("{:?}", sum_pairs(&l5, 10));
}

#[test]
fn test1(){
    let l1 = [1, 4, 8, 7, 3, 15];
    assert_eq!(sum_pairs(&l1, 8), Some((1, 7)));
}

#[test]
fn test2(){
    let l2 = [1, -2, 3, 0, -6, 1];
    assert_eq!(sum_pairs(&l2, -6), Some((0, -6)));
}

#[test]
fn test3(){
    let l3 = [20, -13, 40];
    assert_eq!(sum_pairs(&l3, -7), None);
}

#[test]
fn test4(){
    let l4 = [1, 2, 3, 4, 1, 0];
    assert_eq!(sum_pairs(&l4, 2), Some((1, 1)));
}

#[test]
fn test5(){
    let l5 = [10, 5, 2, 3, 7, 5];
    assert_eq!(sum_pairs(&l5, 10), Some((3, 7)));
}

#[test]
fn test6(){
    let l6 = [4, -2, 3, 3, 4];
    assert_eq!(sum_pairs(&l6, 8), Some((4, 4)));
}

#[test]
fn test7(){
    let l7 = [0, 2, 0];
    assert_eq!(sum_pairs(&l7, 0), Some((0, 0)));
}

#[test]
fn test8() {
    let l8 = [5, 9, 13, -3];
    assert_eq!(sum_pairs(&l8, 10), Some((13, -3)));
}

#[test]
fn test9() {
    assert_eq!(sum_pairs(&[1, 2], 3), Some((1, 2)));
}

#[test]
fn test10() {
    assert_eq!(sum_pairs(&[1, 2, 3, 4, 5, 6, 7, 8, 9], 10), Some((4, 6)));
}