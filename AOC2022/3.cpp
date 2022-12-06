#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

int main(){
    //Rank based on index + 1
    std::string ranks = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string item_types;
    int sum = 0;
    
    //Backpack input
    std::vector<std::string> backpack = {"vJrwpWtwJgWrhcsFMMfFFhFp", "jqHRNqRjqzjGDLGLrsFMfFZSrLrFZsSL", "PmmdzqPrVvPwwTWBwg",
                                         "wMqvLMZHhHMvwLHjbvcjnnSBnvTQFn", "ttgJtRGJQctTZtZT", "CrZsJsPPZsGzwwsLwLmpwMDw"};

    //Find matching items in compartments
    for (std::string str : backpack){
        int i = 0, mid = str.size() / 2, j = mid;
        for(;;){
            if (str.at(i) == str.at(j)){
                item_types.push_back(str.at(i));
                break;
            } else if (j == str.size()-1) {
                j = mid;
                ++i;
            }
            ++j;
        }
    }

    //Compute sum of priority values
    for(char ch : item_types){
        for(int k = 0; k < ranks.size(); ++k){
            if (ch == ranks.at(k)){
                sum += k+1;
            }
        }
    }
    std::cout << "Sum of priority items: " << sum << std::endl;

    return EXIT_SUCCESS;
}