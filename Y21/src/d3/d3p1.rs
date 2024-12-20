use std::fs::File;
use std::io::{self, BufRead};

fn read_file() -> Vec<(String, String)> {
  let file = File::open("src/d2/inp2.txt");
  let file = match file {
    Ok(file) => file,
    Err(_) => return Vec::new(), // Return an empty vector if file can't be opened
  };

  let reader = io::BufReader::new(file);

  let mut instructions: Vec<(String, String)> = Vec::new();

  for line in reader.lines() {}

  instructions
}

pub fn solve() {
  println!("Part one --> ");
}
