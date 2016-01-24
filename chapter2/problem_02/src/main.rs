use std::io::stdin;
use std::env::args;
use std::collections::LinkedList;

fn find_kth_to_last_from_list(some_list : &LinkedList<u8>, index : usize) -> Option<u8> {
    let list_length = some_list.len();
    if index >= list_length {
        return None;
    }
    let mut i = 0;
    for elem in some_list.iter() {
        if i+index == list_length-1 {
            return Some(*elem);
        }
        i = i + 1;
    }
    return None;
}

fn main() {
    let args_len = args().len();
    let mut numbers : LinkedList<u8> = LinkedList::new();
    let index : usize;
    if args_len > 1 {
        let mut arguments = args();
        arguments.next();
        index = arguments.next().unwrap().parse::<usize>().ok().expect("Couldn't parse String to u8");
        for arg in arguments {
            numbers.push_back(arg.parse::<u8>().unwrap());
        }
    } else {
        let mut input = String::new();
        stdin().read_line(&mut input).ok().expect("Couldn't read from stdin");
        index = input.trim().parse::<usize>().ok().expect("Couldn't parse string to u8");
        input.clear();
        for elem in input.split_whitespace() {
            numbers.push_back(elem.parse::<u8>().unwrap());
        }
    }

    match find_kth_to_last_from_list(&numbers, index) {
        Some(n) => println!("{}", n),
        None => println!("The index requested must be strictly less than the number of elements in the list: {}", numbers.len()),
    };
    
}

#[test]
fn test_find_kth_from_list(){
    let mut some_list = LinkedList::new();
    some_list.push_front(1);
    some_list.push_front(2);
    some_list.push_front(3);
    some_list.push_front(4);
    assert_eq!(find_kth_to_last_from_list(&some_list, 0).unwrap(), 1);
    assert_eq!(find_kth_to_last_from_list(&some_list, 1).unwrap(), 2);
    assert_eq!(find_kth_to_last_from_list(&some_list, 2).unwrap(), 3);
    assert_eq!(find_kth_to_last_from_list(&some_list, 3).unwrap(), 4);
}
