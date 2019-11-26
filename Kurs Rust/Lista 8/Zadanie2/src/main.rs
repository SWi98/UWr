fn alphabet_position(text: &str) -> String {
    text.chars().filter(|x| x.is_alphabetic())
        .map(|x| ((x.to_ascii_lowercase() as u32 - 'a' as u32) + 1).to_string())
        .collect::<Vec<String>>()
        .join(" ")
}

fn main() {
    alphabet_position("The sunset sets at twelve o' clock.");
}
