fn row_sum_odd_numbers(n:i64) -> i64 {
    n * n * n
    // odd_sum(n * (n + 1) / 2)) - odd_sum( (n-1) * n / 2) = 
    // = (n * (n + 1) / 2))^2 + ((n - 1) * n / 2) ^2 = n^3

    /*let mut x: i64 = (n-1)*n/2 + 1;
    let mut sum: i64 = 0;
    for _ in 0..n{
        sum += 2 * x - 1;
        x += 1;
       // println!("{}, {}", sum, x)
    }
    return sum; */
}

fn main(){
    println!("{}", row_sum_odd_numbers(3));
}

#[test]
fn test1(){
    assert_eq!(1, row_sum_odd_numbers(1));
}

#[test]
fn test2(){
    assert_eq!(8, row_sum_odd_numbers(2));
}

#[test]
fn test3(){
    assert_eq!(27, row_sum_odd_numbers(3));
}

#[test]
fn test4(){
    assert_eq!(64, row_sum_odd_numbers(4));
}
#[test]
fn test5(){
    assert_eq!(125, row_sum_odd_numbers(5));
}
#[test]
fn test6(){
    assert_eq!(216, row_sum_odd_numbers(6));
}
#[test]
fn test7(){
    assert_eq!(343, row_sum_odd_numbers(7));
}
#[test]
fn test8(){
    assert_eq!(1000, row_sum_odd_numbers(10));
}
#[test]
fn test9(){
    assert_eq!(729, row_sum_odd_numbers(9));
}
#[test]
fn test10(){
    assert_eq!(74088, row_sum_odd_numbers(42));
}
