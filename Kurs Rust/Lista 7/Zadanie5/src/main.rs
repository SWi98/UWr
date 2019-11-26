fn last_digit(lst: &[u64]) -> u64{
    let mut vec: Vec<u64> = lst.to_vec();
    vec.reverse();
    let mut lastDigit: u128 = 1;
    for power in vec{
        if lastDigit == 0{
            lastDigit = 1;
        }
        else if lastDigit == 1{
            lastDigit = power as u128;
        }
        else{
            if power < 20{
                lastDigit = _pow(power, lastDigit % 4 + 4);
            }
            else{
                lastDigit = _pow(power % 20 + 20, lastDigit % 4 + 4);           // %20 ?? https://stackoverflow.com/questions/51304865/last-digit-of-power-list?fbclid=IwAR1OgloyxeIwAB4O_fQt2qa-fDX1FnGGt9ousMxnu0Qlni1xWAZ4L8TgAJ4
            }
        }
    }
    (lastDigit % 10) as u64
}

fn _pow(x: u64, y: u128) -> u128{
    let mut res: u128 = 1;
    for _ in 0..y{
        res = res * (x as u128); 
    }
    return res;
}

fn main() {
    println!("{}", last_digit(&vec![2, 2, 2, 2, 2]));
}

#[test]
fn basic_tests() {
    let tests = vec![
        (vec![], 1),
        (vec![0, 0], 1),
        (vec![0, 0, 0], 0),
        (vec![1, 2], 1),
        (vec![3, 4, 5], 1),
        (vec![4, 3, 6], 4),
        (vec![7, 6, 21], 1),
        (vec![12, 30, 21], 6),
        (vec![2, 2, 2, 0], 4),
        (vec![937640, 767456, 981242], 0),
        (vec![123232, 694022, 140249], 6),
        (vec![499942, 898102, 846073], 6)
    ];

    for test in tests {
        assert_eq!(last_digit(&test.0), test.1);
    }
}