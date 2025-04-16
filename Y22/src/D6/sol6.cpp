//
// Copyright
//

#include "D6/sol6.h"

#include <iostream>
#include <set>
#include <string>

using std::cout;
using std::endl;
using std::string;

int marker(string line) {
  for (int i = 3; i < line.size(); i++) {
    if (line[i] != line[i - 1] && line[i] != line[i - 2] &&
        line[i] != line[i - 3] && line[i - 1] != line[i - 2] &&
        line[i - 1] != line[i - 3] && line[i - 2] != line[i - 3]) {
      return i + 1;
    }
  }
  return -1;
}

int improved_marker(string line) {
  string last_14;
  for (int i = 14; i < line.size(); i++) {
    last_14 = line.substr(i - 14, 14);
    std::set<char> seen;
    for (char c : last_14) {
      seen.insert(c);
    }
    if (seen.size() == 14) {
      return i;
    }
  }
  return -1;
}

void solve_6() {
  string input =
      "cmpmbppqmqsqzzrrswrrnqrnqqjzjvzzqvzvjvnnlclrrjhrrrnggmgwwdhhfttmmjrjzrzr"
      "hrbrgbrbsbjbcjjvpjjcvjvttfwffjtffqqqldqllhthhljhllfffbfbzbczzznmznnrrtgr"
      "gppdcppdfpfjjrggpjgjwgjwgghdggzzshzhrhttmhhdqhqsqgglhljjbggjhggfsfvfggrm"
      "ggwwbwvvwssqtqzqlqvlqqvtthjhjrjssclscsszhzbztbbdhdbbqfbqqvdqdjjjspsqslsn"
      "lljnljjhttdtbdttjpjggtfftlldpdzzqhzqqcwwvggmgmppmhpmpddgjjbzbmzmllndldbl"
      "bwbswsbbmzzwnnpdndzznmnjnjmnnzwwrqwrqrvqvqmmbmhmzzdqqfnqqgnqqfppmnnqzzvv"
      "cfclcrrzfzrzttchttshsphshddrgdggvwgvwwjjzbbprrgwrrcttwbwpwfffqppwnpwpqww"
      "wbmwwjrjprrrsfrfdfrddvdzvzqzgzmgmpgpmmpspdssdlsldsdwssgzgddttqpphllvbvcc"
      "jzjppffsjsbbvnbvbttgwtgtftzzlhzzjvzvsvtsttfrfrsswpwnwccqtqrqqrhqhjhccpfp"
      "gpjgpprnprrscctddqmdqqncqctqqrpqrprwpwnwnrnccmfmdfmfdfnfdnnphhbhttsszgss"
      "vhhprprnrsrrvggdllvfvrvbrbsrbrpphhqbbhllpttjmttrstszzwllbsbzzgmzgzbzcbcb"
      "jcbbjdjpjtttwggqhhpzpzszqqzhqqhrhlrrrvnrnqrqgrqggzccnnjrrcmmzvmmvtmtltvv"
      "lzlmmbnmmbbclljnjhhbjbhbjbbfcbfcfbbqwwftfhttwvwhhwfwcffwvwmmwtwftfjttwdt"
      "wdtwttqnttmdtdjtdjjlzjzhjhwwnbbmdmhhjmhmjjwmmpsmmhrrfnnqrqjrrpmpjpzpbzpz"
      "tppswsmsnnlnppscsgcgsccsfcctbtcctvcvhvjhhccppbrbcrbrmbmvmllnmllgfgmgdmms"
      "lmlrmllhttgrrsttlmmnrrrlqqsjjddzzsbsdbbrjbjvbbfwwwglljplpglltlztzvtzzmbz"
      "bmbmcchlchcnhccbhhhzrrglgmgwwwwrddvmmvdvvpjpnpspmpsmpsscrrphpdhdllrsspcs"
      "psqslsspbbmcbmmdhdwhwpphfhmmfhmhjmjrrhtrtffsddwsddwccvncczlzjzdjzddszdss"
      "tgtbthhjhddwppvhvvvwrvwrrpspjpvjjsmsccszzgpzzmjzmzvmvrmmgbglgppbfppvvqff"
      "gdgtgpgdgnghhbhgbbpbdbrrjrtjtggvzzvttwbwlbwbttrbttvdttpctcrtrccddfrrmqqj"
      "rqqsvqsqzsslnlggmrggnllvdvbvmbmsmwmfmvvdwvwbbnddvfvzzjppbpgpvgppblbzznss"
      "cwssqppgbbfwwfmfzzqqgnnjnffvbfvbbfllbhlltvtnvnbnsnddcjcbjbbjpbbhhjghhqjj"
      "lttnmmhwmhwwddlppsjppgtthllsclcvvlfvvvlzvlvcccrhrrvqrvvzrvzrrmqqbtbnnwss"
      "vhvtttnsttrnnghgdggmgdmmnbnhbhdbddvppvhvlvttzmttljlflvfvpfpwffqbffjllnvl"
      "ltslsttrvrdrmddtwdwmmlplhlnlffmzzrssvsgsffzjfjcffrcrppzfzbbtltjljtjftfmm"
      "mrjmjqmjqmjqmjqjsqqhzzhdhrrcwwbcltfjdgmhvmqmmsclsdgmdqzcvzznwgtdbzgvlpzv"
      "dqrvwpmndtzmdpznnplmbvvmffdpbjztvzpwffvqbwmvbmtwjrdpngrftvgznmtzwzmsrvpg"
      "pzjcdwvnqplfgncgcdtjbhcqztgqpdhwlmrjbzhcfhnzqmpzzghzpfzbgwmlqztnbdnntgdc"
      "fssgzqndhfwdtrbpzbmqjgjflmcllscjnnnrzzsjhnwptjlbhpcwwhsvqqlvjzghnwvzmwtb"
      "jgwfgmpdfcjfswvqzwdbnvlwfbmdcjvgjcdhjfbjccsjqrgdrhrjnhgpvvfjqvfwqpgmgfsb"
      "snlrfnbtpzljmzrjmjlldgbvvwbnpqgsnzzmswtwgshdlwhsttdjlhnnlgbprwltbppttctt"
      "tftrmbjccvwtljqffrcpwnwjgcwjnhmphfsnbfdnfbvzqqlwbnjjdvplrjbflcrwjtrngwzz"
      "nzhsmnwzfbpjrdmjlwzvrvrblrscjlrmswjpbrtjjbsgzwjnfwwgmnbbppqfnlmfsbpwbdnj"
      "mrcvqdhhvrrvmghlbbpfsqzsnbjvrvthnrhlttsnlbgvsdvsmncdglrgpsqjqthnlrhnzpnn"
      "jgvrnmdnrtjbmlppfppnmgjhtbzpztdmclgbqjzsgfjllplpnnmjhgpcfcpcmbnwjsdmfmrq"
      "vqvjfsrnqhbrzdvwcsmmjvqpjnzbgrhwcwggvvjzbrswplgvbbqhdlqptzjvzcznspjbpvfm"
      "gbcfjbgmztmqtlzmzzzpmcdmmvhvnphpcfwcmwqwwqvmwpwhhnspmhrdmjblzhhlphwldfcl"
      "sfjbzhjglvllldnmtjtwqtztfcvjdngslhnsmmlwlpzdbrrthtwfpjfvfljddplfgnhcnwwm"
      "mpgwwspnsprsvprccwvvljwbqwrzqjmwfrnnjbrfsrglnrwdfnsswqwsbpplgnfnvvvhqwmt"
      "gsdwmvnzmbjpbscdtcrmsllljwlntjzpwqvvnznmfddtgrmqbdsczhtvjdwrwvjccrqnjlnq"
      "bvqhhvnmqmrmnqllcjzcjgzwctrntjsnhrwmcqzrwzzqgqlmbqczlgtmtwlztclhwcjsgbdl"
      "frppwrpbnpgsjfhprvzjwnpdwsjwmdcbmljclcgcnsqcpzgvrrbnnhjhblgnpcbzbcdmgjmp"
      "mpcwwdngmggmfqcjcwrzblsfmrslbblhdlwjqrrgtnvcfsccbdgnjcztrblrwbrvdzcnnshw"
      "zzvgcqwpqmjzhzlllbtzmcqpnwwqqlcjtrrzfmdpmpblmwztwqdgbmtfggjwnmffzvszgdmh"
      "fvflthzmwqgqvgmldzpbwbdvrjldhbnzsthqsczttbbthzgzmmrcmzmzmjfrhbtmsbqrbnsn"
      "zzfpvwlwpszdptljqphrdznhbwbfdfhsrqnmlqdcdgbrbsmgwwbbjsmwhzgmqtmfbndzlmlv"
      "mrrvrmqbjqbhhqtvvgbhbmsrtljwmtnhtpwjvlrgqljvgpsfrwgdfbcwlmvfdrrlgwvvzvcf"
      "twpjhcplgwvqbzftjfbmmcpvrrsvbnwqdhtlsfcjzlrmwvgvgwpbffsrrpdpssqhqrqdglnw"
      "cqznzlqqvjzpsdnpwfqtfjqhqwvlfpwrqqmntcnnbfprlwrfdwstvbpjmjdbcdffmwvqbsdn"
      "vcgrtccvcfzpwjscmrtbbjjnmlcztbldfnwbqcpqlshthrcbdrfldcmhtgwrgqhnnglbzgdg"
      "glzjbgjtdvgzgrspjtbhpmzvpplgjpjbthmjtwqqzsslnfrtmpznbqvmccqccrtdvrssmdgr"
      "ptsjglvrmlcwfllptczvpgwbdfbrnpzdzmpfjwdhqlsqlzlzrwcsmhcmjhhfhfvcdrzhsmqb"
      "wcfshslsnswpslbjnrzqllwbnddhrngmjqtnvhrjpcpmggvgqbwtwcmbvhnwggdrzfgmhhvp"
      "qzbvlghsvgmhngwdsrwlzffbpzqmfzvbhbjvqlcswhctpcqnptrvlwblnvpfbzsjnsdjnhqb"
      "zddsnthhcfbcvmqgfmvztlcwjbmdtgvgwqbqgdrvbgbnbcnqwzfzqpsgbvtwlphgvqlzshnd"
      "cbffzcbllgzrzrnhdvqnvtndhcdslqbbhcdftlmnltmsmgfcgvmpbsljdbthjtqlfbmczznw"
      "cvfcsnftsnpzcwfqbfhjpswzfzfswfgtzplppsglsdncblddsmftmfdmmnsjjgg";
  cout << "Day 6 solutions:" << endl;
  cout << "Part A: " << marker(input) << endl;
  cout << "Part B: " << improved_marker(input) << endl;
}
