pub fn highlight(code: &str) -> String {
    let mut res = String::new();
    let vec = code.to_string().chars().collect::<Vec<char>>();
    let mut prev = vec[0];

    for i in 0..vec.len(){

        if (vec[i] != prev && !(vec[i].is_digit(10) && prev.is_digit(10)))|| i == 0 {
            // If current char is different than previous or we just started iterating through the 'code'
            if i != 0 && prev != '(' && prev != ')'{
                // We append "</span>" unless we just started iterating or the previous char shouldn't be highlighted
                res += "</span>";
            }
            match vec[i]{
                'F' => res += "<span style=\"color: pink\">F",
                'L' => res += "<span style=\"color: red\">L",
                'R' => res += "<span style=\"color: green\">R",
                '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9' => 
                res += &("<span style=\"color: orange\">".to_string() + &vec[i].to_string()),
                '(' | ')' => res += &vec[i].to_string(),
                _ => ()
            }
        }

        else{
            res += &vec[i].to_string();
        }

        if i == vec.len() - 1 && vec[i] != '(' && vec[i] != ')' {
            // If we are at the last char and it isn't a char which wasn't to be highlighted
            res += "</span>";
        }

        prev = vec[i];
    }

    return res;
}

fn main() {
    println!("{}", highlight("FF"));
}

