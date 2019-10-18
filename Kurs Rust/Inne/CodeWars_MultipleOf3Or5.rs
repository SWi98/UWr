fn solution(num: i32) -> i32 {
  let mut sum: i32 = 0 ;
  for i in 3..num{
      if i%3 == 0 || i%5 == 0{
          sum += i;
      }
  }
  sum
}

fn solution2(num: i32) -> i32{
    (1..num).fold(0, |acc, x| match x % 3 == 0 || x % 5 == 0 {
        true => acc + x,
        false => acc
    })
} 

fn main(){
    println!("{}", solution2(10));
}