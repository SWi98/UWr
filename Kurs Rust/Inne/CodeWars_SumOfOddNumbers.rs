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