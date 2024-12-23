mod d1;
mod d2;
mod d3;
mod d4;
mod d5;
mod d6;
mod d7;

fn main() {
  const DAY: i8 = 7;
  if DAY == 1 {
    d1::d1p1::solve();
    d1::d1p2::solve();
  } else if DAY == 2 {
    d2::d2p1::solve();
    d2::d2p2::solve();
  } else if DAY == 3 {
    d3::d3p1::solve();
    d3::d3p2::solve();
  } else if DAY == 4 {
    d4::d4p1::solve();
    d4::d4p2::solve();
  } else if DAY == 5 {
    d5::d5p1::solve();
    d5::d5p2::solve();
  } else if DAY == 6 {
    d6::d6p1::solve();
  } else if DAY == 7 {
    d7::d7p1::solve();
  }
}
