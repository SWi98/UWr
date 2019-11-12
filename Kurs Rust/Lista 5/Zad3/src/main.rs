fn solution(n: f64) -> f64 {
    if (n.round() - n).abs() > 0.25{
        if n.round() < n{
            return n.round() + 0.5;
        }
        else{
            return n.round() - 0.5;
        }
    }
    else{
        return n.round() as f64;
    }
}

fn main() {
    solution(4.6);
    solution(-4.6);
}

#[test]
fn test1() {
    assert_eq!(solution(4.6), 4.5);
}
#[test]   
fn test2(){
    assert_eq!(solution(4.2), 4.0);
}
#[test]
fn test3(){
    assert_eq!(solution(4.4), 4.5);
}
#[test]
fn test4(){
    assert_eq!(solution(4.8), 5.0);
}
#[test]
fn test5(){
    assert_eq!(solution(4.9), 5.0);
}
#[test]
fn test6(){
    assert_eq!(solution(4.81231312312312312312312), 5.0);
}
#[test]
fn test7(){
    assert_eq!(solution(0.0), 0.0);
}
#[test]
fn test8(){
    assert_eq!(solution(21999.00000001), 21999.0);
}
#[test]
fn test9(){
    assert_eq!(solution(9.9), 10.0);
}
#[test]
fn test10(){
    assert_eq!(solution(11.5), 11.5);
}