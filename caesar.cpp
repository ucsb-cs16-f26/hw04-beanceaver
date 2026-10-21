#include <cctype>
#include <iostream>
#include <string>

using namespace std;

void usage() {
  std::cout << "USAGE: caesar [-ed] [key]\n";
}

int main(int argc, char** argv) {
  if(argc != 3) {
    usage();
    return 1;
  }
  string ed = argv[1];
  if(ed != "-e" && ed != "-d") {
    usage();
    return 1;
  }
  string key = argv[2];
  for (unsigned int i = 0; i < key.length(); ++i) {
    if (!isdigit(key[i])) {
      usage();
      return 1;
    }
  }

  string text;
  getline(cin, text);
  int ednum = (ed == "-e") ? 1 : -1;
  int shift = stoi(key) % 26 * ednum;
  for (unsigned int i = 0; i < text.size(); ++i) {
    if (islower(text[i])) {
      text[i] = 'a' + (text[i] - 'a' + shift + 26) % 26;
    } else if (isupper(text[i])) {
      text[i] = 'A' + (text[i] - 'A' + shift + 26) % 26;
    }
  }
  cout << text << endl;
  
  return 0;
}
