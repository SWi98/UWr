fn perimeter(n: u64) -> u64 {
    let mut res: u64 = 0;
    let mut _current: u64 = 1;
    let mut _prev: u64 = 0;
    for _i in 0..n+1{
        res += _current;
        _current += _prev;
        _prev = _current - _prev;
    }
    4 * res
}


fn main(){
    println!("{}", perimeter(5))
}

#[test]
fn basics_perimeter() {
    dotest(7, 216);
    dotest(20, 114624);
    dotest(30, 14098308);
}