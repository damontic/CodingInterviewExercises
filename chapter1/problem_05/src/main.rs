use std::env::args;
use std::io::stdin;

fn basic_string_compression(some_string : String) -> String {
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
        some_string
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
    print!("{}", basic_string_compression(input));
}

#[test]
fn test_basic_string_compression_true() {
    assert_eq!(basic_string_compression("aaabbbccc".to_string()), "a3b3c3".to_string());
    assert_eq!(basic_string_compression("abbbcdddddd".to_string()), "a1b3c1d6".to_string());
    assert_eq!(basic_string_compression("abcd".to_string()), "abcd".to_string());
    assert_eq!(basic_string_compression("ccccccccccbbaaaaa".to_string()), "c10b2a5".to_string());
}
