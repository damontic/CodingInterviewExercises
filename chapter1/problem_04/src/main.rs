use std::env::args;
use std::io::stdin;

fn make_spaces_url_compatible(some_string : String) -> String {
    some_string.replace(" ", "%20")
}

fn main() {
    let mut input = String::new();
    input = match args().nth(1) {
        Some(a) => a,
        None => {
            stdin().read_line(&mut input).ok().expect("Couldnt read from STDIN");
            input
        }
    };
    println!("{}", make_spaces_url_compatible(input));
}

#[test]
fn test_make_spaces_url_compatible_true(){
    assert!(make_spaces_url_compatible("hello world".to_string()) == "hello%20world".to_string());
    assert!(make_spaces_url_compatible(" he llo wor ld".to_string()) == "%20he%20llo%20wor%20ld".to_string());
    assert!(make_spaces_url_compatible(" ".to_string()) == "%20".to_string());
    assert!(make_spaces_url_compatible("%20 %20".to_string()) == "%20%20%20".to_string());
}
