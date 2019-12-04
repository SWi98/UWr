fn camel_case(str: &str) -> String {
    str.split_whitespace().map(|x| [&x[..1].to_uppercase(), &x[1..]].join("")).collect()
}

fn main() {
    println!("Hello, world!");
}

#[test]
fn sample_test() {
  assert_eq!(camel_case("test case"), "TestCase");
  assert_eq!(camel_case("camel case method"), "CamelCaseMethod");
  assert_eq!(camel_case("say hello "), "SayHello");
  assert_eq!(camel_case(" camel case word"), "CamelCaseWord");
  assert_eq!(camel_case(""), "");
  assert_eq!(camel_case("a"), "A");
  assert_eq!(camel_case("A"), "A");
}