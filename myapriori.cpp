// Patrick Rode
// 11/15/22
// Data Mining
// HW2

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include <iterator>
#include <stdexcept>


void scanner(std::vector<char> container, std::map<std::string, int> &output);

int main(int argc, char* argv[]){

    if(argc < 3){
        std::cout << "Too few arguements." << std::endl;
        return 0;
    }

    int minSupp = std::atoi(argv[2]);
    std::ifstream f1 (argv[1]);
    std::ofstream f2("output.txt");
    std::string input;
    std::string output;
    std::map<std::string, int> itemSets;
    int i = 1;
    int j = 2;
    int k = 3; 
    int l = 4; 
    int m = 5;
    int n = 6;
    std::vector<char> numbers;
    numbers.push_back('1');
    numbers.push_back('2');
    numbers.push_back('3');
    numbers.push_back('4');
    numbers.push_back('5');
    numbers.push_back('6');

    scanner(numbers, itemSets);
    

    int counter = 1;
    while(!f1.eof()){
        //std::cout << "====Line " << counter << "====" << std::endl;
        ++counter;
        numbers.clear();
        getline(f1, input);

        for(int i = 0; i < input.size(); ++i){
            if(input[i] != ' '){
                
                numbers.push_back(input[i]);
            }
        }
        scanner(numbers, itemSets);
    }
    for(int i = 1; i < 7; ++i){
        for(auto x : itemSets){
            if(x.first.size() == i){
                    
                if(((x.second * 100) / (counter - 1)) >= minSupp){
                    std::cout << x.first << " : " << x.second << std::endl;
                    f2 << " " << x.first << " : " << x.second << std::endl;
                }
            }
        }
    }

    return 0;
}

void scanner(std::vector<char> container, std::map<std::string, int> &output){
    int inc = 1;
    if(output.empty()){
        inc = 0;
    }
    std::vector<std::vector<char>::iterator> its;
    std::string key;
    bool flag = true;

    while(its.size() < container.size()){
        flag = true;
        // 1 create iterator
        if(its.empty()){
            its.push_back(container.begin());
        }
        else{
            its.push_back(std::next(its.back(), 1));
        }
        // 2 assign iterator to beginning spot, or one past previous iterator
        // 3 turn iterator data into string
        while(flag){
            
                
            key = "";
            //key.erase();
            for(auto x : its){
                
                key += *x;
                
            }
            
            if(!output.insert(std::pair<std::string,int>(key, 0)).second){
                ++output[key];
            }
            //std::cout << "insert-" << key << " : " << output[key] << std::endl;

            if(std::next(its.back(), 1) == container.end())
                //if(its.size() > 1 && std::next(its.front(), 1) == its[1])
                if(std::next(its.front(), its.size() - 1) == its.back())
                    flag = false;
            if(its.size() == 1 && std::next(its.front(), 1) == container.end())
                flag = false;
            
            
            bool done = false;
            if(flag){ 
                int index = its.size() - 1;
                while(done == false){
                    ++its[index];
                    //std::cout << *its[index] << std::endl;
                    
                    if(its[index] == container.end()){
                    
                        
                        its[index] = std::next(its[index - 1], 2);
                        // get position of its[index] in container
                        auto containerIndex = std::distance(container.begin(), its[index]);
                        
                        //std::cout << "here" << index << '-' << *its[0]  << std::endl;
                        if(its[index] == container.end() || its[index] == its[index +1]){
                            its[index] = std::next(its[index - 1], 1);
                        }else if(((container.size() - containerIndex + 1) >= (its.size() - index + 1)) && (container.size() - containerIndex + 1) != 0){
                            int i = index + 1;
                            while(i < its.size()){
                                
                                its[i] = std::next(its[i - 1], 1);
                                ++i;
                            }
                            
                        }
                        // for(int v = its.size() - 1; v >= 0; --v){
                        //     std::cout << v << "-" << *its[v] << std::endl;
                        // }
                        //std::cout << "here" << index << '-' << *its[index]  << std::endl;
                        if(index > 0)
                            --index;
                    }
                    else if((its.size() - 1) != index && index != 0){
                        // std::cout << "here-"<< index << std::endl;
                        // for(int v = its.size() - 1; v >= 0; --v){
                        //         std::cout << v << "-" << *its[v] << std::endl;
                        // }
                        if((its[index] == its[index + 1])){
                            
                            its[index] = std::next(its[index - 1], 2);
                            // get position of its[index] in container
                            auto containerIndex = std::distance(container.begin(), its[index]);
                            
                            //std::cout << "here" << index << '-' << *its[0]  << std::endl;
                            if(its[index] == container.end() || its[index] == its[index +1]){
                                its[index] = std::next(its[index - 1], 1);
                            }else if(((container.size() - containerIndex + 1) >= (its.size() - index + 1)) && (container.size() - containerIndex + 1) != 0){
                                int i = index + 1;
                                while(i < its.size()){
                                    
                                    its[i] = std::next(its[i - 1], 1);
                                    ++i;
                                }
                                
                            }
                            // for(int v = its.size() - 1; v >= 0; --v){
                            //     std::cout << v << "-" << *its[v] << std::endl;
                            // }
                            //std::cout << "here" << index << '-' << *its[index]  << std::endl;
                            if(index > 0)
                                --index;
                        }else if((its.size() - 1) == index){
                            std::cout << "queer" << std::endl;
                        }
                        else{
                            done = true;
                        }

                    }
                    else{
                        done = true;
                    }
                    
                }
            }

        }


        
        // 4 insert string into map
        // 5 increment iterator
        // 6 repeat 3-5 until iterator reaches end
        // 7 increment previous iterator, else done if no previous
        // 8 set next iterator in front of previous
        for(int j = 0; j < its.size(); ++j){
            its[j] = std::next(container.begin(), j);
            
        }
        
    }
    
    
}