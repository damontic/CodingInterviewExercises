use std::env::args;
use std::io::stdin;

fn make_spaces_url_compatible(some_string : &str) -> String {
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
    println!("{}", make_spaces_url_compatible(&input));
}

#[test]
fn test_make_spaces_url_compatible_true(){
    assert!(make_spaces_url_compatible("hello world") == "hello%20world");
    assert!(make_spaces_url_compatible(" he llo wor ld") == "%20he%20llo%20wor%20ld");
    assert!(make_spaces_url_compatible(" ") == "%20");
    assert!(make_spaces_url_compatible("%20 %20") == "%20%20%20");
}
