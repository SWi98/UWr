use std::f64::consts::PI;

fn square_area_to_circle(size:f64) -> f64 {
    (size / 4.0) * PI
}

fn main(){
}


fn assert_close(a:f64, b:f64, epsilon:f64) {
    assert!( (a-b).abs() < epsilon, format!("Expected: {}, got: {}",b,a) );
}

#[test]
fn test1() {
  assert_close(square_area_to_circle(9.0), 7.0685834705770345, 1e-8);
}
#[test]
fn test2(){
  assert_close(square_area_to_circle(20.0), 15.70796326794897, 1e-8);
}
#[test]
fn test3(){
    assert_close(square_area_to_circle(100.0), 78.5398163397448309, 1e-8)
}

#[test]
fn test4(){
    assert_close(square_area_to_circle(30.1), 23.640484718263195, 1e-8)
}

#[test]
fn test5(){
    assert_close(square_area_to_circle(17.123192312), 13.448523793346103, 1e-8)
}
