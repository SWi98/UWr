use std::f64::consts::PI;

fn square_area_to_circle(size:f64) -> f64 {
    let x = size.sqrt() / 2.0;
    x * x * PI
    
}

fn main(){
    println!("{jeden}", jeden = square_area_to_circle(64.0));
}
