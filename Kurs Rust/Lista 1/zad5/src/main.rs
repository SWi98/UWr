
fn printer_error(s: &str) -> String {
   // let text = String::from s;
   // let x = 

    let mut len: i32 = 0;
    let mut errors: i32 = 0; 
    for letter in s.chars(){
        if !(letter as u32 >= 97 && letter as u32 <= 109){
            errors = errors + 1;
        }
        len = len + 1;
    }
    return  errors.to_string() + "/" + &len.to_string();
}

fn main() {
}

    #[test]
    fn test1() {
        assert_eq!(&printer_error("aaaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbmmmmmmmmmmmmmmmmmmmxyz"), "3/56");
    }
    #[test]
    fn test2(){
        assert_eq!(&printer_error("kkkwwwaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbmmmmmmmmmmmmmmmmmmmxyz"), "6/60");
    }
    #[test]
    fn test3(){
        assert_eq!(&printer_error("kkkwwwaaaaaaaaaaaaaabbbbbbbbbbbbbbbbbbmmmmmmmmmmmmmmmmmmmxyzuuuuu"), "11/65");
    }
    #[test]
    fn test4(){
        assert_eq!(&printer_error("xxyyzzz1234"), "11/11");
    }
    #[test]
    fn test5(){
        assert_eq!(&printer_error(""), "0/0");
    }