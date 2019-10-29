fn zoom(n: i32) -> String {
    let mut vec = Vec::new();
    let mut res = String::new();
    let mut full_line = Vec::new();
    let mut empty_line = Vec::new();
    let mut full = "■";
    let mut empty = "□";
    for i in 0..n{
        full_line.push("■");
        empty_line.push("□");
    }

    let m = n as usize;
    if n/2 % 2 != 0{
        full = "□";
        empty = "■";
        let mut helper = Vec::new();
        helper = full_line.clone();
        full_line = empty_line;
        empty_line = helper;
    }
    vec.push(full_line.clone());

    for i in 1usize..=(m-1)/2{
        let mut new_line = Vec::new();

        if i%2 == 0{
            new_line = full_line.clone();
            for mut j in (1usize..=i).step_by(2){
                new_line[j] = empty;
                new_line[m-j-1] = empty;
                j+= 1; 
            }
        }

        else{
            new_line = empty_line.clone();
            for mut j in (0usize..=i).step_by(2){
                new_line[j] = full;
                new_line[m-j-1] = full;
            }
        }

        vec.push(new_line);
    }

    for i in 0usize..vec.len() - 1{
        //println!("{}", vec.len() - 2 * i - 2);
        vec.push(vec[vec.len() - 2 * i - 2].clone())
    }

    for v in vec{
        let mut string_line : String = v.concat();
        res += &(string_line + "\n");
    }
    res.pop();
    return res;

}

fn main() {
}


#[test]
fn basic_test_1() {
  assert_eq!(zoom(1), "■");
}

#[test]
fn basic_test_2() {
  assert_eq!(zoom(3), "\
□□□
□■□
□□□"
  );
}

#[test]
fn basic_test_3() {
  assert_eq!(zoom(5), "\
■■■■■
■□□□■
■□■□■
■□□□■
■■■■■"
  );
}

#[test]
fn basic_test_4() {
  assert_eq!(zoom(7), "\
□□□□□□□
□■■■■■□
□■□□□■□
□■□■□■□
□■□□□■□
□■■■■■□
□□□□□□□"
  );
}

#[test]
fn basic_test_5() {
  assert_eq!(zoom(9), "\
■■■■■■■■■
■□□□□□□□■
■□■■■■■□■
■□■□□□■□■
■□■□■□■□■
■□■□□□■□■
■□■■■■■□■
■□□□□□□□■
■■■■■■■■■"
  );
}

#[test]
fn test6(){
    assert_eq!(zoom(25), "\
■■■■■■■■■■■■■■■■■■■■■■■■■
■□□□□□□□□□□□□□□□□□□□□□□□■
■□■■■■■■■■■■■■■■■■■■■■■□■
■□■□□□□□□□□□□□□□□□□□□□■□■
■□■□■■■■■■■■■■■■■■■■■□■□■
■□■□■□□□□□□□□□□□□□□□■□■□■
■□■□■□■■■■■■■■■■■■■□■□■□■
■□■□■□■□□□□□□□□□□□■□■□■□■
■□■□■□■□■■■■■■■■■□■□■□■□■
■□■□■□■□■□□□□□□□■□■□■□■□■
■□■□■□■□■□■■■■■□■□■□■□■□■
■□■□■□■□■□■□□□■□■□■□■□■□■
■□■□■□■□■□■□■□■□■□■□■□■□■
■□■□■□■□■□■□□□■□■□■□■□■□■
■□■□■□■□■□■■■■■□■□■□■□■□■
■□■□■□■□■□□□□□□□■□■□■□■□■
■□■□■□■□■■■■■■■■■□■□■□■□■
■□■□■□■□□□□□□□□□□□■□■□■□■
■□■□■□■■■■■■■■■■■■■□■□■□■
■□■□■□□□□□□□□□□□□□□□■□■□■
■□■□■■■■■■■■■■■■■■■■■□■□■
■□■□□□□□□□□□□□□□□□□□□□■□■
■□■■■■■■■■■■■■■■■■■■■■■□■
■□□□□□□□□□□□□□□□□□□□□□□□■
■■■■■■■■■■■■■■■■■■■■■■■■■"
  );
}