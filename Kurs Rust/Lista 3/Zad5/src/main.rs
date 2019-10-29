fn last_digit(str1: &str, str2: &str) -> i32 {

    fn _modulo(st: &str, a:i32) -> i32{
        let mut res = 0;
        for c in st.chars(){
            res = (res * 10 + c.to_digit(10).unwrap()) % a as u32;
        }
        res as i32
    }


    if str2 == "1"{
        return _modulo(str1, 10);
    }

    else if str2 == "0"{
        return 1;
    }
    else{
        let exp = _modulo(str2, 4);
        if exp == 0 {
            return _modulo(str1, 10).pow(4) % 10;
        }
        else{
            return _modulo(str1, 10).pow(_modulo(str2, 4) as u32)  % 10;
        }
    }
}

fn main(){
}

#[test]
fn test1() {
    assert_eq!(last_digit("4", "1"), 4);
}
#[test]
fn test2(){
    assert_eq!(last_digit("1606938044258990275541962092341162602522202993782792835301376","2037035976334486086268445688409378161051468393665936250636140449354381299763336706183397376"), 6);
}
#[test]
fn test3(){
    assert_eq!(last_digit("3715290469715693021198967285016729344580685479654510946723", "68819615221552997273737174557165657483427362207517952651"), 7);
}
#[test]
fn test4(){
    assert_eq!(last_digit("4", "2"), 6);
}
#[test]
fn test5(){
    assert_eq!(last_digit("9", "7"), 9);
}
#[test]
fn test6(){
    assert_eq!(last_digit("10","10000000000"), 0);
}
#[test]
fn test7(){
    assert_eq!(last_digit("4", "0"), 1);
}
#[test]
fn test8(){
    assert_eq!(last_digit("10", "1"), 0);
}
#[test]
fn test9(){
    assert_eq!(last_digit("100", "0"), 1);
}
#[test]
fn test10(){
    assert_eq!(last_digit("999", "2"), 1);
}