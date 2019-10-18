fn row_sum_odd_numbers(n:i64) -> i64 {
    let mut x: i64 = (n-1)*n/2 + 1;
    let mut sum: i64 = 0;
    for _ in 0..n{
        sum += 2 * x - 1;
        x += 1;
        println!("{}, {}", sum, x)
    }
    return sum;
}

fn main(){
    //println!("{}", row_sum_odd_numbers(1));
   // println!("{}", row_sum_odd_numbers(2));
    println!("{}", row_sum_odd_numbers(3));
    //println!("{}", row_sum_odd_numbers(4));
}
// 1 - 1
// 2 - 2
// 3 - 4 
// 4 - 7
// 5 - 11
// 6 - 16