use std::io::stdin;
use std::env::args;
use std::collections::HashMap;

static ERR_STDIN_INPUT : &'static str = "PROBLEM READING FROM STDIN";

fn has_all_unique_characters(my_string : &str) -> bool {
    let mut characters_map = HashMap::new();
    for i in my_string.chars() {
        if characters_map.contains_key(&i){
            *characters_map.get_mut(&i).unwrap() += 1;
        }else{
            characters_map.insert(i, 1);
        }
    }
    for value in characters_map.values() {
        if *value > 1 {
            return false;
        }
    }
    true
}

fn main() {
    let mut input_string = String::new();
    input_string = match args().nth(1) {
        Some(a) => a,
        None => {
            stdin().read_line(&mut input_string).ok().expect(ERR_STDIN_INPUT);
            input_string
        }
    };
    println!("{}", has_all_unique_characters(&input_string));
}

#[test]
fn test_has_all_unique_characters_is_true(){
    assert!(has_all_unique_characters("abcde"));
}

#[test]
#[should_panic]
fn test_has_all_unique_characters_is_false(){
    assert!(has_all_unique_characters("abcdea"));
}
