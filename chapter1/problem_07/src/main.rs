use std::io::stdin;

fn put_zeros(matrix : Vec<Vec<u8>>) -> Vec<Vec<u8>> {
    let dimensions = matrix.len();
    let mut result = Vec::new();
    for i in 0..dimensions {
        let mut row = Vec::new();
        for j in 0..dimensions {
            if matrix[i][j] == 0 {
                row.clear();
                for _ in 0..dimensions{
                    row.push(0);
                }
                result.push(row);
            }
            row.push(matrix[i][j]);
        }
        result.push(row);
    }
    result
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
