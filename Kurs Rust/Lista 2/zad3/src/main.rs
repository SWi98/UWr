fn string_into_int(s: String) -> i32{
    s.parse().unwrap()
}

fn summy(strng: &str) -> i32 {
    let mut sum: i32 = 0;
    let mut acc: String = "".to_string();
    for c in strng.chars(){
        if c != ' '{
            acc.push(c);
        }
        else{
            println!("_{}_", acc);
            sum = sum + string_into_int(acc);
            acc = "".to_string();
        }
    }
    if acc != "".to_string(){
        sum = sum + string_into_int(acc)
    }
    return sum;
}

fn main() {
    println!("{}", summy("20 10 30 40"));
    //println!("{}", string_into_int("102".to_string()));
}


 #[test]
    fn sample_tests() {
        assert_eq!(summy("1 2 3"), 6);
    }

#[test]
fn test2(){
    assert_eq!(summy("1 2 3 4"), 10);
}
#[test]
fn test3(){
    assert_eq!(summy("1 2 3 4 5"), 15);
}
#[test]
fn test4(){
    assert_eq!(summy("10 10"), 20);
}
#[test]
fn test5(){
    assert_eq!(summy("0 0"), 0);
}