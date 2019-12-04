fn dont_give_me_five(start: isize, end: isize) -> isize {
    (start..=end).map(|x| x.to_string()).filter(|x| !x.contains("5")).count() as isize
}


fn main() {
    println!("Hello, world!");
}
