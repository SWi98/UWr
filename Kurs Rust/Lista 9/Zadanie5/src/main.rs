pub fn range_extraction(a: &[i32]) -> String {
    if a.len() == 0{
        return "".to_string();
    }
    else if a.len() == 1{
        return a[0].to_string();
    }
    
    let mut res = String::new();

    let mut prev: i32 = a[0];
    let mut start: i32 = a[0];
    let mut end: i32 = a[0];
    let mut how_many: i32 = 0;

    for (i, &item) in a.iter().enumerate(){
        if i != 0{
            if item == prev + 1{
                prev = item;
                how_many += 1;
            }
            else if how_many >= 2{
                res += &start.to_string();
                res.push('-');
                res += &prev.to_string();
                res.push(',');
                prev = item;
                start = item;
                how_many = 0;
            }
            else if how_many == 1{
                res += &(prev-1).to_string();
                res.push(',');
                res += &prev.to_string();
                res.push(',');
                prev = item;
                start = item;
                how_many = 0;
            }
            else{
                res += &prev.to_string();
                res.push(',');
                prev = item;
                start = item;
            }
        }
        end = item;
    }

    if how_many > 0{
        if how_many >= 2{
            res += &start.to_string();
            res.push('-');
            res += &prev.to_string();
        }
        else if how_many == 1{
            res += &(prev-1).to_string();
            res.push(',');
            res += &prev.to_string();
        }
    }

    if end > a[a.len() - 2] + 1{
        res += &end.to_string();
    }
    return res;
}

fn main() {
    println!("{}", range_extraction(&[-17, -14, -11, -8, -6, -4, -3, 0, 2, 3, 6, 7, 10, 13, 15, 17, 20, 23, 26, 28, 31, 34, 37, 40, 42, 43, 45, 46, 48, 49, 52]));
}

#[test]
fn test1(){
    assert_eq!("-17,-14,-11,-8,-6,-4,-3,0,2,3,6,7,10,13,15,17,20,23,26,28,31,34,37,40,42,43,45,46,48,49,52",
    range_extraction(&[-17, -14, -11, -8, -6, -4, -3, 0, 2, 3, 6, 7, 10, 13, 15, 17, 20, 23, 26, 28, 31, 34, 37, 40, 42, 43, 45, 46, 48, 49, 52]));
}

#[test]
    fn test2() {
        assert_eq!("-3--1,2,10,15,16,18-20", range_extraction(&[-3,-2,-1,2,10,15,16,18,19,20]));
    }
    #[test]
    fn test3() {
        assert_eq!("1-5", range_extraction(&[1, 2, 3, 4, 5]));
    }
    #[test]
    fn test4() {
        assert_eq!("1,3,5,7,9", range_extraction(&[1, 3, 5, 7, 9]));
    }
    #[test]
    fn test5() {
        assert_eq!("1,3", range_extraction(&[1,3]));
    }
    #[test]
    fn test6() {
        assert_eq!("1-3", range_extraction(&[1, 2, 3]));
    }
    #[test]
    fn test7() {
        assert_eq!("-1-1", range_extraction(&[-1, 0, 1]));
    }
    #[test]
    fn test8() {
        assert_eq!("-9--7,-5--1,1,2,4", range_extraction(&[-9, -8, -7, -5, -4, -3, -2, -1, 1, 2, 4]));
    }
    #[test]
    fn test9() {
        assert_eq!("1-10,12", range_extraction(&[1,2,3,4,5,6,7,8,9,10,12]));
    }
    #[test]
    fn test10() {
        assert_eq!("-9--1,1", range_extraction(&[-9,-8,-7,-6,-5,-4,-3,-2,-1,1]));
    }