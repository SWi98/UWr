use std::collections::HashMap;

struct MorseDecoder {
    morse_code: HashMap<String, String>,
}

impl MorseDecoder {
    fn new() -> MorseDecoder {
        MorseDecoder{ morse_code :
        [("....-", "4"),("--..--", ","),(".--", "W"),(".-.-.-", "."),("..---", "2"),(".", "E"),("--..", "Z"),(".----", "1"),(".-..", "L"),
        (".--.", "P"),(".-.", "R"),("...", "S"),("-.--", "Y"),("...--", "3"),(".....", "5"),("--.", "G"),("-.--.", "("),("-....", "6"),
        (".-.-.", "+"),("...-..-", "$"),(".--.-.", "@"),("...---...", "SOS"),("..--.-", "_"),("-.", "N"),("-..-", "X"),("-----", "0"),
        ("....", "H"),("-...", "B"),(".---", "J"),("---...", ","),("-", "T"),("---..", "8"),("-..-.", "/"),("--.-", "Q"),("...-", "V"),
        ("----.", "9"),("--", "M"),("-.-.-.", ";"),("-.-.--", "!"),("..-.", "F"),("..--..", "?"),("-...-", "="),("..-", "U"),(".----.", "'"),
        ("---", "O"),("-.--.-", ")"),("..", "I"),("-....-", "-"),(".-..-.", "\""),(".-", "A"),("-.-.", "C"),("-..", "D"),(".-...", "&"),
        ("--...", "7"),("-.-", "K")].iter().map(|(k, v)| (k.to_string(), v.to_string())).collect()}
    }

    fn decode_morse(&self, encoded: &str) -> String {
        println!("{}", encoded);
        let words: Vec<&str> = encoded.trim().split("   ").collect();
        let mut res = String::new();

        for word in words{
            let characters: Vec<&str> = word.split(" ").collect();
            for character in &characters{
                if character.len() > 0{
                    res += self.morse_code.get(*character).unwrap();
                }
            }
            res.push(' ');
        }

        res.pop();
        return res;
    }
    
}    

fn main() {
    let decoder = MorseDecoder::new();
    println!("{}", decoder.decode_morse(".... . -.--   .--- ..- -.. ."));
}

#[test]
fn test1(){
    let decoder = MorseDecoder::new();
    assert_eq!(decoder.decode_morse(""), "");
}
