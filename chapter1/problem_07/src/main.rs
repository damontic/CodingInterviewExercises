use std::io::stdin;
use std::collections::HashSet;

fn put_zeros(matrix : Vec<Vec<u8>>) -> Vec<Vec<u8>> {
    let mut row_indices = HashSet::new();
    let mut col_indices = HashSet::new();
    
    let dimensions = matrix.len();
    for i in 0..dimensions {
        for j in 0..dimensions {
            if matrix[i][j] == 0 {
                row_indices.insert(i);
                col_indices.insert(j);
                break
            }
        }
    }
    
    let mut matrix = matrix;
    for i in row_indices {
        for j in 0..dimensions {
            matrix[i][j] = 0;
        }
    }
    for i in col_indices {
        for j in 0..dimensions {
            matrix[j][i] = 0;
        }
    }
    matrix
}

fn main() {
    let mut input = String::new();
    stdin().read_line(&mut input).ok().expect("Couldnt read from STDIN");
    let dimensions = input.trim().parse::<u8>().ok().expect("Couldnt parse to u8");
    let mut matrix = Vec::new();
    for _ in 0..dimensions {
        input.clear();
        stdin().read_line(&mut input).ok();
        let row : Vec<u8> = input.split(" ").map(|x| x.trim().parse::<u8>().ok().unwrap()).collect();
        matrix.push(row);
    }
    println!("{:?}", put_zeros(matrix));
}

#[test]
fn test_put_zeros(){
    let mut m1 = Vec::new();
    m1.push(vec![1,2,3,4]);
    m1.push(vec![5,0,7,8]);
    m1.push(vec![9,10,11,12]);
    m1.push(vec![13,14,15,16]);

    let mut m2 = Vec::new();
    m2.push(vec![1,0,3,4]);
    m2.push(vec![0,0,0,0]);
    m2.push(vec![9,0,11,12]);
    m2.push(vec![13,0,15,16]);
    
    assert_eq!(put_zeros(m1), m2);

    let mut m3 = Vec::new();
    m3.push(vec![1,2,3,4]);
    m3.push(vec![5,0,7,8]);
    m3.push(vec![9,10,0,12]);
    m3.push(vec![13,14,15,0]);

    let mut m4 = Vec::new();
    m4.push(vec![1,0,0,0]);
    m4.push(vec![0,0,0,0]);
    m4.push(vec![0,0,0,0]);
    m4.push(vec![0,0,0,0]);
    
    assert_eq!(put_zeros(m3), m4);

}
