use std::io::stdin;

fn rotate_90(matrix : Vec<Vec<u8>>) -> Vec<Vec<u8>> {
    let mut rotated_matrix = Vec::new();
    let dimensions = matrix.len();
    for i in 0..dimensions {
        let mut row = Vec::new();
        for j in 0..dimensions {
            row.push(matrix[j][dimensions-i-1]);
        }
        rotated_matrix.push(row);
    }
    rotated_matrix
}

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).ok().expect("Couldnt read from STDIN.");
    let dimensions = input.trim().parse::<u8>().ok().unwrap();
    let mut matrix = Vec::new();
    for _ in 0..dimensions {
        input.clear();
        stdin().read_line(&mut input).ok().expect("Couldnt read from STDIN.");
        let numbers : Vec<u8> = input.trim().split(" ").map(|x| x.parse::<u8>().ok().unwrap()).collect();
        matrix.push(numbers);
    }
    println!("{:?}", rotate_90(matrix));
}

#[test]
fn test_rotate_90(){
    let mut m1 = Vec::new();
    m1.push(vec![1,2,3,4]);
    m1.push(vec![5,6,7,8]);
    m1.push(vec![9,10,11,12]);
    m1.push(vec![13,14,15,16]);

    let mut m2 = Vec::new();
    m2.push(vec![4,8,12,16]);
    m2.push(vec![3,7,11,15]);
    m2.push(vec![2,6,10,14]);
    m2.push(vec![1,5,9,13]);
    
    assert_eq!(rotate_90(m1), m2);
}
