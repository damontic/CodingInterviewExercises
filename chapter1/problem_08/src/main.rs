use std::io::stdin;
use std::env::args;

fn is_rotation(base : &str, possible_rotation : &str) -> bool {
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
    println!("{}", is_rotation(&base, &possible_rotation));
}

#[test]
fn test_is_rotation(){
    assert!(is_rotation("hola", "ahol"));
    assert!(!is_rotation("chao", "asd"));
    assert!(is_rotation("buenas", "nasbue"));
    assert!(!is_rotation("sdfasdfs", "asdfsaf"));
    assert!(is_rotation("david", "vidda"));
}
