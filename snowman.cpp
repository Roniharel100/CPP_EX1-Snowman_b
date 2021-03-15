#include "snowman.hpp"
#include <array>

using namespace std;
using namespace ariel;

const array<string, 4> hats = {
        "       \n _===_ ",
        "  ___  \n ..... ",
        "   _   \n  /_\\  ",
        "  ___  \n (_*_) "
};

const array<string, 4> noses = {",", ".", "_", " "};
const array<string, 4> eyes = {".", "o", "O", "-"};
const array<string, 4> torsos = {
        " : ",
        "] [",
        "> <",
        "   "
};

const array<string, 4> bases = {
        " : ",
        "\" \"",
        "___",
        "   "
};

const array<string, 4> left_arms = {" <", "\\ ", " /", "  "};
const array<string, 4> right_arms = {" >", "/ ", " \\", "  "};

string ariel::snowman(int code) {
    if (code < 0) {
        throw invalid_argument("Negative snowman code");
    }

    if (code < min_snowman_code || code > max_snowman_code) {
        throw invalid_argument("Illegal snowman code");
    }

    int current = code;
    int base = current % base_num - 1;
    if (base < min_index || base > max_index) {
        throw out_of_range("Illegal base code");
    }

    current /= base_num;

    int torso = current % base_num - 1;
    if (torso < min_index || torso > max_index) {
        throw out_of_range("Illegal torso code");
    }

    current /= base_num;

    int right_arm = current % base_num - 1;
    if (right_arm < min_index || right_arm > max_index) {
        throw out_of_range("Illegal right arm code");
    }

    current /= base_num;

    int left_arm = current % base_num - 1;
    if (left_arm < min_index || left_arm > max_index) {
        throw out_of_range("Illegal left arm code");
    }

    current /= base_num;

    int right_eye = current % base_num - 1;
    if (right_eye < min_index || right_eye > max_index) {
        throw out_of_range("Illegal right eye code");
    }

    current /= base_num;

    int left_eye = current % base_num - 1;
    if (left_eye < min_index || left_eye > max_index) {
        throw out_of_range("Illegal left eye code");
    }

    current /= base_num;

    int nose = current % base_num - 1;
    if (nose < min_index || nose > max_index) {
        throw out_of_range("Illegal nose code");
    }

    current /= base_num;

    int hat = current % base_num - 1;
    if (hat < min_index || hat > max_index) {
        throw out_of_range("Illegal hat code");
    }

    string res;

    //  HHHHH
    //  HHHHH
    res += hats.at(hat);
    res += "\n";

    // X(LNR)Y
    res += left_arms.at(left_arm).substr(top_arm, 1) + '(';
    res += eyes.at(left_eye) + noses.at(nose) + eyes.at(right_eye) + ')' + right_arms.at(right_arm).substr(top_arm, 1);
    res += "\n";

    // X(TTT)Y
    res += left_arms.at(left_arm).substr(bottom_arm, 1) + '(';
    res += torsos.at(torso) + ')' + right_arms.at(right_arm).substr(bottom_arm, 1);
    res += "\n";

    //  (BBB)
    res += " (";
    res += bases.at(base);
    res += ") ";

    return res;
}