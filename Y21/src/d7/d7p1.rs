use std::fs::File;
use std::io::{self, BufRead};

fn read_file() -> Vec<i8> {
  let file = match File::open("src/d7/inp7.txt") {
    Ok(file) => file,
    Err(_) => return Vec::new(),
  };

  let reader = io::BufReader::new(file);
  println!("Reading file... {:?}", reader);

  Vec::new()
}

pub fn solve() {
  read_file();
  println!("Part one --> {}", 0);
}
