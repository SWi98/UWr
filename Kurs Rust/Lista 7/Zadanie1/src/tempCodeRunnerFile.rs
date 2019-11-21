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