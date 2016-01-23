use std::env::args;
use std::io::stdin;

fn basic_string_compression(some_string : &str) -> String {
    let mut compressed = String::new();
    let mut previous_char : char = '!';
    let mut counter = 0;
    for c in some_string.chars() {
        if previous_char != c {
            compressed.push(previous_char);
            compressed = compressed + &counter.to_string();
            counter = 1;
        }else{
            counter += 1;
        }
        previous_char = c;
    }
    compressed.push(previous_char);
    compressed = compressed + &counter.to_string();
    let result = compressed[2..].to_string();
    if result.len() > some_string.len() {
        some_string.to_string()
    }else{
        result
    }
}

fn main() {
    let mut input = String::new();
    input = match args().nth(1) {
        Some(s) => s,
        None => {
            stdin().read_line(&mut input).ok().expect("Couldn't read from STDIN");
            input
        }
    };
    print!("{}", basic_string_compression(&input));
}

#[test]
fn test_basic_string_compression_true() {
    assert_eq!(basic_string_compression("aaabbbccc"), "a3b3c3");
    assert_eq!(basic_string_compression("abbbcdddddd"), "a1b3c1d6");
    assert_eq!(basic_string_compression("abcd"), "abcd");
    assert_eq!(basic_string_compression("ccccccccccbbaaaaa"), "c10b2a5");
}
