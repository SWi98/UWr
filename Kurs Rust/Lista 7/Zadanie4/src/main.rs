fn john_and_ann(n: i32) -> (Vec<i32>, Vec<i32>){
    let mut john_vec: Vec<i32> = vec![0];
    let mut ann_vec: Vec<i32> = vec![1];
    for i in 1..n{
        john_vec.push(i - ann_vec[john_vec[(i-1) as usize] as usize]);
        ann_vec.push(i - john_vec[ann_vec[(i-1) as usize] as usize]);
    }
    return (john_vec, ann_vec);
}

fn john(n: i32) -> Vec<i32> {
    john_and_ann(n).0
}
fn ann(n: i32) -> Vec<i32> {
    john_and_ann(n).1
}
fn sum_john(n: i32) -> i32 {
    john(n).iter().sum()
}
fn sum_ann(n: i32) -> i32 {
    ann(n).iter().sum()
}
fn main() {
}
