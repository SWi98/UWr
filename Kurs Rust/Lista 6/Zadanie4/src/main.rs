fn comp(a: Vec<i64>, b: Vec<i64>) -> bool {
    let mut _a = a.iter().map(|x| x * x).collect::<Vec<i64>>();
    let mut _b = b;
    _a.sort();
    _b.sort();
    _a == _b
}

fn main() {
    let a1 = vec![121, 144, 19, 161, 19, 144, 19, 11];
    let a2 = vec![11*11, 121*121, 144*144, 19*19, 161*161, 19*19, 144*144, 19*19];
    comp(a1, a2);
}
