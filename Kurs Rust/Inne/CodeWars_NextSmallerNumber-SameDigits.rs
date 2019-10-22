fn next_smaller_number(n: u64) -> Option<u64> {
    let mut number: Vec<u64> = n.to_string().chars().map(|x| x.to_digit(10).unwrap() as u64).collect();
    number.reverse();
    println!("{:?}", number);
    for i in 0..(number.len()-1){
        //iterating from the end of our number (0..len because our vector is reversed) we want to find the first digit
        //bigger than its predecessor (in 1234 it's 3 because it's smaller than 4 and we iterated from the end)
        if number[i+1] > number[i]{
            let mut smallest_digit: u64 = number[i];   
            let mut s_d_position: usize = i;
            for j in 0..i{
                if number[j] < number[i+1] && smallest_digit < number[j]{
                    smallest_digit = number[j];
                    s_d_position = j;
                }
            }
            number.swap(i+1, s_d_position);
            &number[0..(i+1)].sort();
            number.reverse();
            if number[0] != 0{
                return Some(number.iter().fold(0, |acc, x| acc*10 + x));
            }
        }
    }
    None
}

fn main(){
    println!("{:?}", next_smaller_number(10));
}