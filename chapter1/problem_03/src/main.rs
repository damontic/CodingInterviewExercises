use std::io::stdin;
use std::env::args;
use std::collections::HashMap;

fn is_permutation(word1 : &str, word2 : &str) -> bool {
    let mut character_map = HashMap::new();
    for i in word1.chars(){
        if character_map.contains_key(&i) {
            *character_map.get_mut(&i).unwrap() += 1;
        }else{
            character_map.insert(i, 1);
        }
    }
    for i in word2.chars(){
        if character_map.contains_key(&i) {
            *character_map.get_mut(&i).unwrap() -= 1;
        }else{
            return false;
        }
    }
    for i in character_map.values(){
        if *i != 0 {
            return false;
        }
    }
    true
}

fn get_arg(n : usize) -> String {
    let mut input = String::new();
    input = match args().nth(n) {
        Some(a) => a,
        None => {
            stdin().read_line(&mut input).ok().expect("Couldn't read from command line...");
            input
        }
    };
    input
}

fn main() {
    let word1 : String = get_arg(1);
    let word2 : String = get_arg(2);
    println!("{}", is_permutation(&word1, &word2));
}

#[test]
fn test_is_permutation(){
    assert!(is_permutation("buenas", "buenas"));
    assert!(is_permutation("anitalavalatina", "anitalavalatina"));
    assert!(is_permutation("qwertyuiop", "poiuytrewq"));
    assert!(is_permutation("zmqp", "qpmz"));
    assert!(!is_permutation("buenas", "buena"));
    assert!(!is_permutation("aanitalavalatina", "anitalavalatina"));
    assert!(!is_permutation("aqwertyuiop", "poiuytrewq"));
    assert!(!is_permutation("azmqp", "qpmz"));
}
