// neural_network_cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <list>
#include <math.h>

using namespace std;

void print(std::list<std::string> const &list)
{
    for (auto const &i: list) {
        std::cout << i << std::endl;
    }
}


// c++ program for printing a nested vector
#include <iostream>
#include <iterator>
//#include <list>
#include <vector>
using namespace std;

void printNestedVector(vector<vector<float> > nested_vector)
{
    cout << "[\n";

    // nested_vector`s iterator(same type as nested_vector)
    // to iterate the nested_vector
    vector<vector<float> >::iterator nested_vector_itr;

    // Print the nested_vector
    for (nested_vector_itr = nested_vector.begin();
        nested_vector_itr != nested_vector.end();
        ++nested_vector_itr
        ) {

        cout << "  [";

        // normal_vector`s iterator(same type as temp_vector)
        // to iterate the normal_vector
        vector<float>::iterator single_vector_itr;

        // pointer of each vector one by one in nested vector
        // as loop goes on
        vector<float>& single_vector_pointer = *nested_vector_itr;

        for (single_vector_itr = single_vector_pointer.begin();
            single_vector_itr != single_vector_pointer.end();
            single_vector_itr++) {
            cout << " " << *single_vector_itr << " ";
        }
        cout << "]\n";
    }
    cout << "]\n";
}


void printNestedNestedVector(vector<vector<vector<float>>> nested_nested_vector)
{
    cout << "[\n";
    vector<vector<vector<float>>>::iterator nested_nested_vector_itr;

    for (nested_nested_vector_itr = nested_nested_vector.begin();
        nested_nested_vector_itr != nested_nested_vector.end();
        ++nested_nested_vector_itr
        ) {

        cout << "[\n";

        // nested_vector`s iterator(same type as nested_vector)
        // to iterate the nested_vector
        vector<vector<float> >::iterator nested_vector_itr;

        vector<vector<float>>& nested_vector_pointer = *nested_nested_vector_itr;

        // Print the nested_vector
        for (nested_vector_itr = nested_vector_pointer.begin();
            nested_vector_itr != nested_vector_pointer.end();
            ++nested_vector_itr
            ) {

            cout << "  [";

            // normal_vector`s iterator(same type as temp_vector)
            // to iterate the normal_vector
            vector<float>::iterator single_vector_itr;

            // pointer of each vector one by one in nested vector
            // as loop goes on
            vector<float>& single_vector_pointer = *nested_vector_itr;

            for (single_vector_itr = single_vector_pointer.begin();
                single_vector_itr != single_vector_pointer.end();
                single_vector_itr++) {
                cout << " " << *single_vector_itr << " ";
            }
            cout << "]\n";
        }
        cout << "]\n";
    }
    cout << "]\n";
}

void initialize_network(int n_inputs, int n_hidden, int n_outputs)
{
    // https://www.geeksforgeeks.org/nested-list-in-c-stl/
    // but changed from lists to vectors to allow direct access to elements
    cout << "Initialize Network\n";

    vector<vector<vector<float>>>network;
    vector<vector<float>> hidden_layer;
    vector<float> single_weight_vector;

    for (int i = 0; i < n_hidden; i++) {
        //hidden_layer.push_back({ 0 });
        for (int j = 0; j < n_inputs + 1; j++) {
            float random_float = ((float)rand()) / (float)RAND_MAX;
            single_weight_vector.push_back(random_float);
        }
        hidden_layer.push_back(single_weight_vector);

        // delete all elements from single_vector
        single_weight_vector.erase(single_weight_vector.begin(),
            single_weight_vector.end());
        //weight_layer.push_back(hidden_layer);
    }
    //cout << "hidden layer:" << endl;
    //for (auto v : hidden_layer)
    //    cout << v << "\n";
    //printNestedVector(hidden_layer);

    network.push_back(hidden_layer);

    //printNestedNestedVector(weight_layer);


    vector<vector<float>> output_layer;
    //vector<float> single_weight_vector;

    for (int i = 0; i < n_outputs; i++) {
        //hidden_layer.push_back({ 0 });
        for (int j = 0; j < n_hidden + 1; j++) {
            float random_float = ((float)rand()) / (float)RAND_MAX;
            single_weight_vector.push_back(random_float);
        }
        output_layer.push_back(single_weight_vector);

        // delete all elements from single_vector
        single_weight_vector.erase(single_weight_vector.begin(),
            single_weight_vector.end());
        //weight_layer.push_back(hidden_layer);
    }

    network.push_back(output_layer);

    printNestedNestedVector(network);
}



int main()
{
    //cout << "Hello World!\n";
    
    int tom, dick, harry;
    tom = 10;
    dick = 20;
    harry = 3254;
    //cout << tom + dick + harry << endl;
    
    int myNumber = 10;
    int myNumber2 = 5;
    //cout << myNumber + myNumber2 << endl;

    string result = myNumber == myNumber2 ? "equal" : "not equal";
    //cout << result << endl;

    char ch = 'a';
    //cout << ch << endl;

    // null character
    char mychar = '\0';

    string myString = "abcdef";
    //cout << myString << endl;
    //cout << myString[2] << endl;

    string ms = "Hi ";
    ms += "there!";
    //cout << ms << endl;

    initialize_network(2, 3, 2);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file