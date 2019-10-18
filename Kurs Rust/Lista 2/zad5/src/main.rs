fn next_bigger_number(n: i64) -> i64 {
    let mut number: Vec<i64> = n.to_string().chars().map(|x| x.to_digit(10).unwrap() as i64).collect();
    number.reverse();

    for i in 0..(number.len()-1){
        //iterating from the end of our number (0..len because our vector is reversed) we want to find the first digit
        //bigger than its predecessor (in 1234 it's 3 because it's smaller than 4 and we iterated from the end)
        if number[i+1] < number[i]{
            let mut smallest_digit: i64 = number[i];   
            let mut s_d_position: usize = i;
            for j in 0..i{
                if number[j] > number[i+1] && smallest_digit > number[j]{
                    smallest_digit = number[j];
                    s_d_position = j;
                }
            }
            number.swap(i+1, s_d_position);
            &number[0..(i+1)].sort();
            &number[0..(i+1)].reverse();
            number.reverse();
            return number.iter().fold(0, |acc, x| acc*10 + x)
        }
    }
    -1
}

fn main(){
}

#[test]
fn test1(){
    assert_eq!(1243, next_bigger_number(1234));
}
#[test]
fn test2(){
    assert_eq!(536489, next_bigger_number(534986));
}
/*#[test]
#[test]
#[test]
#[test]
#[test]
#[test]
#[test]
#[test]*/