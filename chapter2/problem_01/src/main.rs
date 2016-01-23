use std::io::stdin;
use std::env::args;
use std::collections::LinkedList;

fn remove_duplicates(some_list : LinkedList<u8>) -> LinkedList<u8> {
    let mut result : LinkedList<u8> = LinkedList::new();
    'outer : for new_elem in some_list.iter() {
        for elem in result.iter() {
            if new_elem == elem {
                continue 'outer;
            }
        }
        result.push_back(*new_elem);
    }
    result
}

fn main() {
    let mut some_list : LinkedList<u8> = LinkedList::new();
    let args_len = args().len();
    if args_len > 1 {
        for arg_index in 1..args_len {
            let arg : String = args().nth(arg_index).unwrap();
            some_list.push_back(arg.parse::<u8>().unwrap());
        }
    } else {
        let mut input : String = String::new();
        stdin().read_line(&mut input).ok().expect("Couldn't read from STDIN.");
        for elem in input.split_whitespace(){
            some_list.push_back(elem.parse::<u8>().ok().expect("Couldn't parse to u8"));
        }
    }
    println!("{:#?}", remove_duplicates(some_list));
}

#[test]
fn test_remove_duplicates(){
    let mut test_linked_list : LinkedList<u8> = LinkedList::new();
    test_linked_list.push_front(2);
    test_linked_list.push_front(2);
    test_linked_list.push_front(3);
    test_linked_list.push_front(4);
    test_linked_list.push_front(5);
    let mut test_linked_list_result : LinkedList<u8> = LinkedList::new();
    test_linked_list_result.push_front(2);
    test_linked_list_result.push_front(3);
    test_linked_list_result.push_front(4);
    test_linked_list_result.push_front(5);
    assert_eq!(remove_duplicates(test_linked_list), test_linked_list_result);

    let mut test_linked_list2 : LinkedList<u8> = LinkedList::new();
    test_linked_list2.push_front(2);
    test_linked_list2.push_front(2);
    test_linked_list2.push_front(3);
    test_linked_list2.push_front(3);
    test_linked_list2.push_front(3);
    let mut test_linked_list_result2 : LinkedList<u8> = LinkedList::new();
    test_linked_list_result2.push_front(2);
    test_linked_list_result2.push_front(3);
    assert_eq!(remove_duplicates(test_linked_list2), test_linked_list_result2);    
    
}
