use std::io::stdin;
use std::env::args;
use std::collections::HashMap;

fn is_permutation(word1 : String, word2 : String) -> bool {
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
    println!("{}", is_permutation(word1, word2));
}

#[test]
fn test_is_permutation_true(){
    assert!(is_permutation("buenas".to_string(), "buenas".to_string()));
    assert!(is_permutation("anitalavalatina".to_string(), "anitalavalatina".to_string()));
    assert!(is_permutation("qwertyuiop".to_string(), "poiuytrewq".to_string()));
    assert!(is_permutation("zmqp".to_string(), "qpmz".to_string()));
}

#[test]
#[should_panic]
fn test_is_permutation_false(){
    assert!(is_permutation("buenas".to_string(), "buena".to_string()));
    assert!(is_permutation("aanitalavalatina".to_string(), "anitalavalatina".to_string()));
    assert!(is_permutation("aqwertyuiop".to_string(), "poiuytrewq".to_string()));
    assert!(is_permutation("azmqp".to_string(), "qpmz".to_string()));
}
