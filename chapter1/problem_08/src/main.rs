use std::io::stdin;
use std::env::args;

fn is_rotation(base : String, possible_rotation : String) -> bool {
    let all_rotations : String = format!("{0}{0}", base);
    all_rotations.contains(&possible_rotation)
}

fn read_argument(position : usize) -> String {
    let mut input = String::new();
    input = match args().nth(position){
        Some(a) => a,
        None => {
            stdin().read_line(&mut input).ok().expect("Couldn't read from STDIN");
            input
        }
    };
    input
}

fn main() {
    let base = read_argument(1);
    let possible_rotation = read_argument(2);
    println!("{}", is_rotation(base, possible_rotation));
}

#[test]
fn test_is_rotation(){
    assert!(is_rotation("hola".to_string(), "ahol".to_string()));
    assert!(!is_rotation("chao".to_string(), "asd".to_string()));
    assert!(is_rotation("buenas".to_string(), "nasbue".to_string()));
    assert!(!is_rotation("sdfasdfs".to_string(), "asdfsaf".to_string()));
    assert!(is_rotation("david".to_string(), "vidda".to_string()));
}
