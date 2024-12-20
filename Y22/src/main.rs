mod d1;
mod d2;
mod d3;

fn main() {
  const DAY: i8 = 3;
  if DAY == 1 {
    d1::d1p1::solve();
    d1::d1p2::solve();
  } else if DAY == 2 {
    d2::d2p1::solve();
    d2::d2p2::solve();
  } else if DAY == 3 {
    d3::d3p1::solve();
    d3::d3p2::solve();
  }
}
