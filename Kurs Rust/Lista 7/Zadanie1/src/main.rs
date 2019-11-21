fn chessboard_cell_color(cell1: &str, cell2: &str) -> bool {
    let mut sum1 = 0;
    let mut sum2 = 0;
    for c in cell1.chars(){
        sum1 += c as u32;
    }
    for c in cell2.chars(){
        sum2 += c as u32;
    }
    return sum1 % 2 == sum2 % 2;
}

fn main() {
}
#[test]
fn basic_tests() {
    
    assert_eq!(chessboard_cell_color("A1", "A1"), true);
}
#[test]
fn test2(){
    assert_eq!(chessboard_cell_color("A1", "C3"), true);
}
#[test]
fn test3(){
    assert_eq!(chessboard_cell_color("A1", "H3"), false);    
}
#[test]
fn test4(){
    assert_eq!(chessboard_cell_color("A1", "A2"), false);
}
#[test]
fn test5(){
    assert_eq!(chessboard_cell_color("A1", "C1"), true);
}
#[test]
fn test6(){
    assert_eq!(chessboard_cell_color("A1", "A3"), true);
}
#[test]
fn test7(){
    assert_eq!(chessboard_cell_color("A1", "A5"), true);
}
#[test]
fn test8(){
    assert_eq!(chessboard_cell_color("B1", "B1"), true);
}
#[test]
fn test9(){
    assert_eq!(chessboard_cell_color("H8", "G1"), true);
}
