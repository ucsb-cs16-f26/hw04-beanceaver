#include <cctype>
#include <iostream>
#include <string>

using namespace std;

void encrypt(string key, string &text);
void decrypt(string key, string &text);
void usage() {
  std::cout << "USAGE: substitution [-ed] [key]\n";
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
  if (key.length() != 26) {
    usage();
    return 1;
  }
  for (unsigned int i = 0; i < key.length(); ++i) {
    if (isdigit(key[i])) {
      usage();
      return 1;
    }
  }
  for (unsigned int i = 0; i < key.length(); ++i) {
    for (unsigned j = i + 1; j < key.length(); ++j) {
      if (toupper(key[i]) == toupper(key[j])) {
        usage();
        return 1;
      }
    }
  }

  string text;
  getline(cin, text);
  bool ednum = (ed == "-e") ? 1 : 0;
  if (ednum) {
    encrypt(key, text);
  } else {
    decrypt(key, text);
  }
  cout << text << endl;

  return 0;
}


void encrypt(string key, string &text) {
  for (unsigned int i = 0; i < text.length(); ++i) {
    if (islower(text[i])) {
      text[i] = tolower(key[text[i] - 'a']);
    } else if (isupper(text[i])) {
      text[i] = toupper(key[text[i] - 'A']);
    }
  }
}

void decrypt(string key, string &text) {
  for (unsigned int i = 0; i < text.length(); ++i) {
    int index;
    for (unsigned int j = 0; j < key.length(); ++j) {
      if (toupper(text[i]) == toupper(key[j])) {
        index = j;
        break;
      }
    }
    if (islower(text[i])) {
      text[i] = 'a' + index;
    } else if (isupper(text[i])) {
      text[i] = 'A' + index;
    }
  }
}